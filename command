[COMMAND]
Main command             0xF0000000         //4 bits
Sub command              0x0FFFFFFF         //28 bits

1. Magic key:            0x11111111
2. COMUNICATION
    (1) ACK              0x20000001
    (2) NACK             0x20000002
4. GPIO COMMAND:
    (1) LL_GPIO_LOW      0x31000000 //1
    (2) LL_GPIO_HIGH     0x32000000 //2
    (3) LL_GPIO_2        0x30000001 //3
    (4) LL_GPIO_3        0x30000002 //3
    (5) LL_GPIO_4        0x30000004
    (6) LL_GPIO_5        0x30000008
    (7) LL_GPIO_6        0x30000010
    (8) LL_GPIO_7        0x30000020
    (9) LL_GPIO_8        0x30000040
    (10) LL_GPIO_9       0x30000080
    (11) LL_GPIO_10      0x30000100
    (12) LL_GPIO_11      0x30000200
    (13) LL_GPIO_12      0x30000400
    (14) LL_GPIO_13      0x30000800
    (15) LL_GPIO_16      0x30001000
    (16) LL_GPIO_17      0x30002000
    (17) LL_GPIO_18      0x30004000
    (18) LL_GPIO_19      0x30008000
    (19) LL_GPIO_20      0x30010000
    (20) LL_GPIO_21      0x30020000
    (21) LL_GPIO_22      0x30040000
    (22) LL_GPIO_23      0x30080000
    (23) LL_GPIO_24      0x30100000
    (24) LL_GPIO_25      0x30200000
    (25) LL_GPIO_26      0x30400000
    (26) LL_GPIO_27      0x30800000
