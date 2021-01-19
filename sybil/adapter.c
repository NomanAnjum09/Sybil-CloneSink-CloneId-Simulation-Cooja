 //
// 
//
#include "contiki.h"
#include <stdio.h>
#include "adapter.h"
#include "dev/serial-line.h"
#include "packet-handler.h"
#include "packet-buffer.h"

#define PRINTF(...) printf(__VA_ARGS__)

void to_controller(packet_t* p){
    /** Rearrange packet format
     * p: 1 16 0 1 0 3 2 98 0 1 2 255 1 0 2 83
     * Sink -> Controller: 1 16 0.1 0.3 2 98 0.1 2 255 1 0 2 83
     * */
    int i;
    printf("Sink -> Controller: ");
    printf("%d %d %d.%d %d.%d %d %d %d.%d ",
           p->header.net, p->header.len, p->header.dst.u8[0], p->header.dst.u8[1],
           p->header.src.u8[0], p->header.src.u8[1], (uint8_t)p->header.typ, p->header.ttl,
           p->header.nxh.u8[0], p->header.nxh.u8[1]);
    for (i=0; i < (p->header.len - PLD_INDEX); ++i){
        printf("%d ",get_payload_at(p,i));
    }
    printf("\n");
}

PROCESS(adapter_proc, "Adapter process" );
AUTOSTART_PROCESSES(&adapter_proc);
PROCESS_THREAD(adapter_proc, ev, data){
    PROCESS_BEGIN();
        while (1){
            PROCESS_WAIT_EVENT();
            if (ev == serial_line_event_message){
                int i, LEN;
                char *line;
                line = (char *) data;
                uint8_t *packet = (uint8_t *) line;
                LEN = packet[1] - 32;
                uint8_t packet_array[LEN];

                for (i = 0; i < LEN; i++){
                    packet_array[i] = packet[i] - (uint8_t)32;
                }

                packet_t *p = get_packet_from_array(packet_array);
                printf("Received from controller: ");
                for (i=0; i < LEN; i++){
                    printf("%d ", packet_array[i]);
                }
                printf("\n");
                p->info.rssi = 0;
                handle_packet(p);
            }
        }
    PROCESS_END();
}

