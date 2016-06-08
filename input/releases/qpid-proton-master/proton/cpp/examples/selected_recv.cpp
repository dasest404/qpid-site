/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

#include "proton/connection.hpp"
#include "proton/default_container.hpp"
#include "proton/messaging_handler.hpp"
#include "proton/receiver_options.hpp"
#include "proton/source_options.hpp"
#include "proton/url.hpp"

#include <iostream>

#include <proton/config.hpp>

namespace {

    // Example custom function to configure an AMQP filter,
    // specifically an APACHE.ORG:SELECTOR
    // (http://www.amqp.org/specification/1.0/filters)

    void set_filter(proton::source_options &opts, const std::string& selector_str) {
        proton::source::filter_map map;
        proton::symbol filter_key("selector");
        proton::value filter_value;
        // The value is a specific AMQP "described type": binary string with symbolic descriptor
        proton::codec::encoder enc(filter_value);
        enc << proton::codec::start::described()
            << proton::symbol("apache.org:selector-filter:string")
            << proton::binary(selector_str)
            << proton::codec::finish();
        // In our case, the map has this one element
        map[filter_key] = filter_value;
        opts.filters(map);
    }
}


class selected_recv : public proton::messaging_handler {
  private:
    proton::url url;

  public:
    selected_recv(const std::string& u) : url(u) {}

    void on_container_start(proton::container &c) PN_CPP_OVERRIDE {
        proton::source_options opts;
        set_filter(opts, "colour = 'green'");
        proton::connection conn = c.connect(url);
        conn.open_receiver(url.path(), proton::receiver_options().source(opts));
    }

    void on_message(proton::delivery &, proton::message &m) PN_CPP_OVERRIDE {
        std::cout << m.body() << std::endl;
    }
};

int main(int argc, char **argv) {
    try {
        std::string url = argc > 1 ? argv[1] : "127.0.0.1:5672/examples";

        selected_recv recv(url);
        proton::default_container(recv).run();

        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 1;
}