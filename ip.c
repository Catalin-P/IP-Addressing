// 312CB_Picior_Catalin
#include<stdio.h>
// definim valoarea int cu toti bitii setati pe 1
#define MAX_U_INT 4294967295
// prelucram adresa din format X.X.X.X in format zecimal
unsigned int prel_adresa() {
    // declaram 4 octeti pentru fiecare X
    unsigned char oct1, oct2, oct3, oct4;
    scanf("%hhd.%hhd.%hhd.%hhd", & oct1, & oct2, & oct3, & oct4);
    // returnam bitii celor 4 octeti intr-un unsigned int
    return 0 | oct4 | (oct3 << 8) | (oct2 << 16) | (oct1 << 24);
}
// prelucram adresa din format zecimal in format X.X.X.X
void dec_to_adresa(unsigned int ip) {
    // declaram 4 octeti pentru fiecare X
    // shiftam succesiv pentru a pastra doar bitii care ne intereseaza
    unsigned char oct1 = ip >> 24;
    unsigned char oct2 = (ip << 8) >> 24;
    unsigned char oct3 = (ip << 16) >> 24;
    unsigned char oct4 = (ip << 24) >> 24;
    // afisam octetii zecimal
    printf("%u.%u.%u.%u", oct1, oct2, oct3, oct4);
}
// prelucram adresa din format zecimal in format X.X.X.X
void dec_to_adresa_oct(unsigned int ip) {
    // declaram 4 octeti pentru fiecare X
    unsigned char oct1 = ip >> 24;
    unsigned char oct2 = (ip << 8) >> 24;
    unsigned char oct3 = (ip << 16) >> 24;
    unsigned char oct4 = (ip << 24) >> 24;
    // afisam octetii octal
    printf("%o.%o.%o.%o", oct1, oct2, oct3, oct4);
}
// prelucram adresa din format zecimal in format X.X.X.X
void dec_to_adresa_hex(unsigned int ip) {
    // declaram 4 octeti pentru fiecare X
    unsigned char oct1 = ip >> 24;
    unsigned char oct2 = (ip << 8) >> 24;
    unsigned char oct3 = (ip << 16) >> 24;
    unsigned char oct4 = (ip << 24) >> 24;
    // afisam octetii hexadecimal
    printf("%X.%X.%X.%X", oct1, oct2, oct3, oct4);
}
// prelucram un nr dat de cifre de 1 intr-o masca in format zecimal
unsigned int mask_to_dec(int nr_1) {
    // declaram si initializam o masca cu totii bitii setati pe 1
    unsigned int msk = MAX_U_INT;
    // returnam 0 in cazul in care nr_1=0
    if (nr_1 == 0) {
        return 0;
    }
    // shiftam masca la stanga cu nr de zerouri (32(4 octeti)-nr_1)
    return msk << (8 * sizeof(int) - nr_1);
}
// verificam daca doua adrese de retea in format zecimal sunt identice
void is_same_network(unsigned int adresa_1, unsigned int adresa_2) {
    if (adresa_1 == adresa_2) {
        printf("DA\n");
    } else {
        printf("NU\n");
    }
}
// verificam corectitudinea unei masti im format zecimal
int is_msk_correct(unsigned int adresa) {
    // returnam 0 daca masca este 0
    if (adresa == 0) {
        return 0;
    }
    // declaram si initializam complementul mastii
    unsigned int msk = (~adresa);
    /* in cazul in care complementul mastii adunat cu 1 este
       o putere a lui 2(are un singur bit de 1 setat), atunci
       masca este corecta si returnam 1
    */
    if ((msk & (msk + 1)) == 0) {
        return 1;
    } else {
        return 0;
    }
}
// corectam o masca gresita
unsigned int correcting_mask(unsigned int adresa) {
    int i, bit_nr;
    bit_nr = 0;
    // parcurgem masca de la MSB la LSB
    for (i = 31; i >= 0; i--) {
        // numaram toti bitii pana la primul 0, inclusiv
        if ((adresa & (1 << i)) != 0) {
            bit_nr++;
        } else {
            bit_nr++;
            /* shiftam la dreapta apoi la stanga cu restul de 
               biti(32(4 bytes)-contor) pentru a-i seta cu 0,
               corectand masca
            */
            return (adresa >> (32 - bit_nr) << (32 - bit_nr));
        }
    }
    // ne asiguram ca functia returneaza o valoare pentru orice caz posibil
    return -1;
}
// afisam adresa din format zecimal in format binar
void dec_to_bin(unsigned int adresa) {
    int i, bit_nr;
    bit_nr = 0;
    for (i = 31; i >= 0; i--) {
        // parcurgem adresa si printam 0 sau 1 dupa cum este setat bitul i
        if ((adresa & (1 << i)) == 0) {
            printf("0");
        } else {
            printf("1");
        }
        // incrementam bitul curent la care se afla parcurgerea
        bit_nr++;
        // aifsam "."intre 2 octeti
        if (bit_nr == 8 || bit_nr == 16 || bit_nr == 24) {
            printf(".");
        }
    }
}
int main() {
    int nr_set, i;
    // citim numarul de seturi de input
    scanf("%d", & nr_set);
    for (i = 0; i < nr_set; i++) {
        // afisam nr testului
        printf("%d\n", i+1);
        int msk_2, n, j;
        // citim si prelucram msk_1 in format zecimal
        unsigned int msk_1 = prel_adresa();
        // citim msk_2
        scanf("%d", & msk_2);
        // citim si prelucram ip_1 si ip_2
        unsigned int ip_1 = prel_adresa();
        unsigned int ip_2 = prel_adresa();
        // task 0
        printf("-0 ");
        dec_to_adresa(ip_1);
        printf("/%d\n", msk_2);
        unsigned int msk_2_dec = mask_to_dec(msk_2);
        // task 1
        printf("-1 ");
        dec_to_adresa(msk_2_dec);
        // task 2
        printf("\n-2 ");
        dec_to_adresa_oct(msk_1);
        printf(" ");
        dec_to_adresa_hex(msk_1);
        // task 3
        printf("\n-3 ");
        // obtinem adresele de retea pentru ip_1 si ip_2
        unsigned int adr_retea_ip1 = (ip_1 & msk_2_dec);
        unsigned int adr_retea_ip2 = (ip_2 & msk_2_dec);
        // obtinem adresa de broadcast pentru ip_1
        unsigned int adr_broad_ip_1 = (ip_1 | (~msk_2_dec));
        dec_to_adresa(adr_retea_ip1);
        // task 4
        printf("\n-4 ");
        dec_to_adresa(adr_broad_ip_1);
        // task 5
        printf("\n-5 ");
        is_same_network(adr_retea_ip1, adr_retea_ip2);
        // task 6&7
        printf("-6 ");
        if (is_msk_correct(msk_1) == 1) {
            printf("DA\n-7 ");
            dec_to_adresa(msk_1);
            printf("\n-8 ");
        } else {
            printf("NU\n-7 ");
            dec_to_adresa(correcting_mask(msk_1));
            printf("\n-8 ");
        }
        // task 8
        dec_to_bin(ip_1);
        // task 9
        printf("\n-9 ");
        scanf("%d", & n);
        for (j = 0; j < n; j++) {
            int msk_crt;
            unsigned int net = prel_adresa();
            scanf("/%d", & msk_crt);
            /* declaram si initializam 2 adrese de retea
               (adresa de retea curenta a lui ip_2 si 
               adresa de retea curenta)
            */
            unsigned int adr_retea_ip2_crt = (ip_2 & mask_to_dec(msk_crt));
            unsigned int adr_retea_crt = (net & mask_to_dec(msk_crt));
            // verificam daca cele doua adrese de retea coincid
            if (adr_retea_ip2_crt == adr_retea_crt) {
                // afisam indicele adresei curente
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}
