
#include <iostream>
#include <time.h>

/*
1 ~ 25 ������ ���ڸ� �����ϱ� ���� �迭 25��¥���� �����.
1 ~ 25 ������ ���ڸ� ���� �����ش�.
while���� �̿��Ͽ� ���ѷ����� ���� 5x5�� ����ϰ� ���ڸ� �Է¹޴´�.
�Է¹��� ���ڰ� 0�̶�� ������ �����ϰ� 1 ~ 25 ������ ���ڶ�� �ش� ���ڸ�
ã�Ƽ� *�� ����Ѵ�.
������ ��� *�� �ٲ�� �� ī��Ʈ�� �����Ѵ�.
���� 5��, ���� 5��, �밢�� 2�ٿ� ���� �ϼ��� ���� üũ�Ͽ� 5�� �̻��̸�
������ �����Ѵ�.
*/

void main()
{
    srand(time(0));
    rand();

    int Number[25] = {};

    // AI�� ����� ���� �迭�� �����.
    int AINumber[25] = {};
    bool Open[25] = {};
    bool AIOpen[25] = {};
    int Input = -1;
    int LineCount = 0;
    int AILineCount = 0;
    int StarCount = 0;
    int AIStarCount = 0;
    for (int i = 0; i < 25; i++)
    {
        Number[i] = i + 1;
        AINumber[i] = i + 1;
    }

    for (int i = 0; i < 100; i++)
    {
        int Index1 = rand() % 25;
        int Index2 = rand() % 25;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;

        Index1 = rand() % 25;
        Index2 = rand() % 25;

        Temp = AINumber[Index1];
        AINumber[Index1] = AINumber[Index2];
        AINumber[Index2] = Temp;
    }
    while (true)
    {
        system("cls");

        //�÷��̾� ���� ���
        printf("-------------------Player---------------------\n");
        
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (!Open[i * 5 + j])
                    printf("%d\t", Number[i * 5 + j]);
                else
                    printf("*\t");

            }
            printf("\n");
        }
        printf("�ϼ��� �� : %d\n", LineCount);
        // AI ���
        printf("================== AI ==================\n");
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (!AIOpen[i * 5 + j])
                    printf("%d\t", AINumber[i * 5 + j]);
                else
                    printf("*\t");
            }

            printf("\n");
        }

        printf("�ϼ��� �� : %d\n", AILineCount);
        LineCount = 0;
        AILineCount = 0;
        printf("���ڸ� �Է��ϼ��� : ");
        scanf_s("%d", &Input);
        if (Input == 0)
            break;
        else if (Input < 0 || Input > 25)
            continue;
        //�÷��̾� ����üũ
        for (int i = 0; i < 25; ++i)
        {
            if (Input == Number[i])
            {
                Open[i] = true;
            }
            if (Input == AINumber[i])
            {
                AIOpen[i] = true;
            }
            
        }

        for (int i = 0; i < 5; i++)
        {
            StarCount = 0;
            for (int j = 0; j < 5; j++)
            {
                if (Open[i * 5 + j])
                    StarCount++;
                if (StarCount >= 5)
                    LineCount++;
            }
        }
        for (int j = 0; j < 5; j++)
        {
            StarCount = 0;
            for (int i = 0; i < 5; i++)
            {
                if (Open[i * 5 + j])
                    StarCount++;
                if (StarCount >= 5)
                    LineCount++;
            }
        }
        if (Open[0] && Open[6] && Open[12] && Open[18] && Open[24])
            LineCount++;
        if (Open[4] && Open[8] && Open[12] && Open[16] && Open[20])
            LineCount++;

        // AI ���� üũ
        for (int i = 0; i < 5; i++)
        {
            AIStarCount = 0;
            for (int j = 0; j < 5; j++)
            {
                if (AIOpen[i * 5 + j])
                    AIStarCount++;
                if (AIStarCount >= 5)
                    AILineCount++;
            }
        }
        for (int j = 0; j < 5; j++)
        {
            AIStarCount = 0;
            for (int i = 0; i < 5; i++)
            {
                if (AIOpen[i * 5 + j])
                    AIStarCount++;
                if (AIStarCount >= 5)
                    AILineCount++;
            }
        }


       


        if (LineCount >= 5)
        {
            printf("�÷��̾�¸�");
            break;
        }
        if (AILineCount >= 5)
        {
            printf("AI�¸�");
            break;
        }
        
    }

}