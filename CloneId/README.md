# SDN-WISE Controller & Trickle timing implementation in Contiki for energy efficiency

## build firmwares
run RUNME.sh

## build emulated firmware for Cooja
COOJA_BUILD=1

## turn on SDN_WISE debug
SDN_WISE_DEBUG=1

## set to 1 in order to turn on Trickle timer, otherwise set to 0 to use original SDNWISE timer
TRICKLE_ON=1

## Trickle timer debug 
TRICKLE_DEBUG=1

## Paper

@INPROCEEDINGS{Hieu1807:Integrating,

AUTHOR="Nguyen Quang Hieu and Nguyen {Huu Thanh} and Huong Thu Truong and Thu
Ngo-Quynh",

TITLE="Integrating Trickle Timing in Software Defined {WSNs} for Energy Efficiency",

BOOKTITLE="2018 IEEE Seventh International Conference on Communications and

Electronics (ICCE) (IEEE ICCE 2018)",

ADDRESS="Hue City, Vietnam",

DAYS=17,

MONTH=jul,

YEAR=2018,
}