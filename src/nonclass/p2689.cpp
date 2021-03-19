#include <cstdio>

enum bit
{
    LOW = 0,
    HIGH = 1
};

enum i2cerror
{
    NO_ERROR = 0,
    NO_STARTBIT = 1,
    NO_STOPBIT = 2,
    NO_ACK_FROM_SLAVE = 3,
    NO_ACK_FOR_DATA = 4
};

void i2c(void);
int main(void)
{
    int numberOfDataSets = 0;
    scanf("%d", &numberOfDataSets);
    for (int loop = 0; loop < numberOfDataSets; loop++)
        i2c();
    return 0;
}

void i2c(void)
{
    char c = '\0';
    unsigned int numberOfSignalSamples = 0,
                 index = 0,
                 decimalAddress = 0;
    i2cerror error = NO_STARTBIT;
    bit clock = LOW,
        data = LOW,
        clockCycle = LOW,
        dataCycle = LOW,
        run = LOW,
        address[7] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW},
        op = LOW,
        ack = LOW;

    scanf("%d", &numberOfSignalSamples);
    bit signal[numberOfSignalSamples * 2];

    // Input Signal Samples
    for (unsigned int loop = 0; loop < numberOfSignalSamples * 2; loop++)
    {
        scanf(" %c", &c);
        signal[loop] = (c == '0' ? LOW : HIGH);
    }

    // Debug Output
    // for (unsigned int loop = 0; loop < numberOfSignalSamples; loop++)
    //     printf("%c%c%c", signal[loop * 2] == LOW ? '0' : '1', signal[(loop * 2) + 1] == LOW ? '0' : '1', loop != numberOfSignalSamples - 1 ? ' ' : '\n');

    // Simulation
    for (unsigned int loop = 0; loop < numberOfSignalSamples; loop++)
    {
        if (error != NO_ERROR && error != NO_STARTBIT)
            break;
        clock = signal[loop * 2];
        data = signal[(loop * 2) + 1];
        switch (clock)
        {
        case LOW:
            dataCycle = data;
            clockCycle = LOW;
            break;
        case HIGH:
            switch (run)
            {
            case LOW:
                if (clockCycle == HIGH && dataCycle == HIGH && data == LOW)
                {
                    // printf("START BIT\n");
                    run = HIGH;
                    if (error == NO_STARTBIT)
                        error = NO_ERROR;
                    index = 0;
                }
                // else if (dataCycle == HIGH)
                // printf("IDLE\n");
                break;
            case HIGH:
                switch (ack)
                {
                case LOW:
                    if (index <= 7)
                    {
                        if (index < 7)
                            address[index] = dataCycle;
                        else
                            op = dataCycle;
                        // else
                        // printf("%s\n", (op = dataCycle) == LOW ? "WRITE" : "READ");
                        index++;
                    }
                    else if ((ack = dataCycle) == HIGH)
                        index = 0;
                    break;
                case HIGH:
                    if (clockCycle == LOW && dataCycle != data)
                        error = NO_STOPBIT;
                    else if (clockCycle == HIGH && data == HIGH && dataCycle == LOW)
                    {
                        // printf("STOP BIT\n");
                        // printf("TOTAL TRANSFER %u BYTE(s)\n", index / 8);
                        run = LOW;
                    }
                    else
                    {
                        index++;
                        if (index % 9 == 0)
                        {
                            if (dataCycle == LOW)
                                error = NO_ACK_FOR_DATA;
                            // else
                            // printf("\n");
                        }
                        // else
                        // printf("%c", dataCycle == LOW ? '0' : '1');
                    }
                    break;
                }
            }
            clockCycle = HIGH;
        }
    }
    for (int loop = 0; loop < 7; loop++)
        decimalAddress = (decimalAddress << 1) + (address[loop] == LOW ? 0 : 1);

    if (error == NO_ERROR)
    {
        if (ack == LOW)
            error = NO_ACK_FROM_SLAVE;
        else if (run == HIGH)
            error = NO_STOPBIT;
    }

    switch (error)
    {
    case NO_ERROR:
        printf("%s OF %u %s %s SLAVE %X\n",
               (op == LOW) ? "WRITE" : "READ",
               index / 8,
               (index / 8) > 1 ? "BYTES" : "BYTE",
               (op == LOW) ? "TO" : "FROM",
               decimalAddress);
        break;
    case NO_STARTBIT:
        printf("ERROR NO START BIT\n");
        break;
    case NO_STOPBIT:
        printf("ERROR NO STOP BIT\n");
        break;
    case NO_ACK_FROM_SLAVE:
        printf("ERROR NO ACK FROM SLAVE %X\n", decimalAddress);
        break;
    case NO_ACK_FOR_DATA:
        printf("ERROR NO ACK FOR DATA\n");
        break;
    }
    return;
}