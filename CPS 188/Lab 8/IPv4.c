#include <stdio.h>
#include <string.h>

// define structure
typedef struct address_t{
    int a;
    int b;
    int c;
    int d;
    char nick[15];
}address;

// check for pairs
int localnet(address a, address b){
    if(a.a == b.a && a.b == b.b){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    // Open file
    FILE* iplist;
    iplist = fopen("L8_ip.txt", "r");

    int a = 1;
    int b = 1;
    int c = 1;
    int d = 1;
    char nick[15];
    address ip[300];
    int size = 0;
    int i;
    int j;

// run through file, store addresses and nicknames
    while(a != 0 && b != 0 && c != 0 && d != 0 && strcmp(nick, "sentinel") != 0){
        fscanf(iplist, "%d.%d.%d.%d %s", &a, &b, &c, &d, &nick);
        ip[size].a = a;
        ip[size].b = b;
        ip[size].c = c;
        ip[size].d = d;
        strncpy(ip[size].nick, nick, 15);

        size++;
    }
    // close file
    fclose(iplist);

    // Loop through array, check for pairs
    for(i = 0; i < size/2-1; i++){
        for(j = 0; j < size - 1; j++){
            if(localnet(ip[i],ip[j]) == 1 && j != i){
                printf("\nServers %s and %s are on the same local network", ip[i].nick, ip[j].nick);
            }
        }
    }
    
    // Print full list of addresses
    printf("\nAddresses: ");
    for(i = 0; i < size-1; i++){
        printf("\n%d.%d.%d.%d %s", ip[i].a, ip[i].b, ip[i].c, ip[i].d, ip[i].nick);
    }

    return 0;
}