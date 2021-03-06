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

# Qpid Broker-J 7.1.1 Release Notes

Qpid Broker-J is a message broker written in Java that stores, routes,
and forwards messages using AMQP.

For more information about this release, including download links and
documentation, see the [release overview](index.html).


## New features and improvements

 - [QPID-8275](https://issues.apache.org/jira/browse/QPID-8275) - [Broker-J] Allow setting queue exclusive policy in Web Management Console
 - [QPID-8279](https://issues.apache.org/jira/browse/QPID-8279) - [Broker-J] Upgrade Jackson dependencies

## Bugs fixed

 - [QPID-8273](https://issues.apache.org/jira/browse/QPID-8273) - [CVE-2019-0200][Broker-J][AMQP 0-8..0-10] Broker can crash on receiving malformed commands using AMQP protocols 0-8...0-10 and resending malformed messages
 - [QPID-8276](https://issues.apache.org/jira/browse/QPID-8276) - [Broker-J] Broker can leak closed NonBlockingConnection objects and eventually run out of heap memory
 - [QPID-8280](https://issues.apache.org/jira/browse/QPID-8280) - [Broker-J] Legacy REST API for bindings fails to create and delete binding

## Tasks

 - [QPID-8277](https://issues.apache.org/jira/browse/QPID-8277) - [Broker-J] Release Qpid Broker-J 7.1.1