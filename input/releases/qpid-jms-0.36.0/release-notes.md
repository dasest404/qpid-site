;;
;; Licensed to the Apache Software Foundation (ASF) under one
;; or more contributor license agreements.  See the NOTICE file
;; distributed with this work for additional information
;; regarding copyright ownership.  The ASF licenses this file
;; to you under the Apache License, Version 2.0 (the
;; "License"); you may not use this file except in compliance
;; with the License.  You may obtain a copy of the License at
;; 
;;   http://www.apache.org/licenses/LICENSE-2.0
;; 
;; Unless required by applicable law or agreed to in writing,
;; software distributed under the License is distributed on an
;; "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
;; KIND, either express or implied.  See the License for the
;; specific language governing permissions and limitations
;; under the License.
;;

# Qpid JMS 0.36.0 Release Notes

Qpid JMS is a complete [Java Message Service][jms] 2.0 client built
using the [Qpid Proton]({{site_url}}/proton/index.html) protocol
engine.

For more information about this release, including download links and
documentation, see the [release overview](index.html).

[jms]: http://en.wikipedia.org/wiki/Java_Message_Service


## New features and improvements

 - [QPIDJMS-391](https://issues.apache.org/jira/browse/QPIDJMS-391) - Add support for the use of native OpenSSL based providers
 - [QPIDJMS-408](https://issues.apache.org/jira/browse/QPIDJMS-408) - update to proton-j 0.29.0

## Bugs fixed

 - [QPIDJMS-407](https://issues.apache.org/jira/browse/QPIDJMS-407) - Reconnect not working reliable for connections with more than 1 producer JMS session

## Tasks

 - [QPIDJMS-410](https://issues.apache.org/jira/browse/QPIDJMS-410) - update testing dependencies to current versions