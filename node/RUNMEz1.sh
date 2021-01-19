#!/bin/bash
TARGET="z1"
COOJA_BUILD=0
SDN_WISE_DEBUG=1
TRICKLE_ON=0
TRICKLE_DEBUG=0
SEND_DATA=1
DATA_REPLY=1

mkdir z1_firmwares

make TARGET=$TARGET DEFINES=COOJA=$COOJA_BUILD,SINK=1,_MY_ADDRESS=1,SDN_WISE_DEBUG=$SDN_WISE_DEBUG,TRICKLE_ON=$TRICKLE_ON,TRICKLE_DEBUG=$TRICKLE_DEBUG,SEND_DATA=$SEND_DATA,DATA_REPLY=$DATA_REPLY
mv sdn-wise.$TARGET z1_firmwares/sink.$TARGET
make TARGET=$TARGET clean

make TARGET=$TARGET DEFINES=COOJA=$COOJA_BUILD,SINK=0,_MY_ADDRESS=2,SDN_WISE_DEBUG=$SDN_WISE_DEBUG,TRICKLE_ON=$TRICKLE_ON,TRICKLE_DEBUG=$TRICKLE_DEBUG,SEND_DATA=$SEND_DATA,DATA_REPLY=$DATA_REPLY
mv sdn-wise.$TARGET z1_firmwares/node.$TARGET
make TARGET=$TARGET clean