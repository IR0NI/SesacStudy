
#include <iostream>
#include <time.h>

/*
1 ~ 25 사이의 숫자를 저장하기 위한 배열 25개짜리를 만든다.
1 ~ 25 사이의 숫자를 골고루 섞어준다.
while문을 이용하여 무한루프를 돌며 5x5로 출력하고 숫자를 입력받는다.
입력받은 숫자가 0이라면 게임을 종료하고 1 ~ 25 사이의 숫자라면 해당 숫자를
찾아서 *로 출력한다.
한줄이 모두 *로 바뀌면 줄 카운트가 증가한다.
가로 5줄, 세로 5줄, 대각선 2줄에 대해 완성된 줄을 체크하여 5줄 이상이면
게임을 종료한다.
*/

void main()
{
    srand(time(0));
    rand();

    int Number[25] = {};

    // AI가 사용할 숫자 배열을 만든다.
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

        //플레이어 정보 출력
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
        printf("완성된 줄 : %d\n", LineCount);
        // AI 출력
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

        printf("완성된 줄 : %d\n", AILineCount);
        LineCount = 0;
        AILineCount = 0;
        printf("숫자를 입력하세요 : ");
        scanf_s("%d", &Input);
        if (Input == 0)
            break;
        else if (Input < 0 || Input > 25)
            continue;
        //플레이어 숫자체크
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

        // AI 숫자 체크
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
            printf("플레이어승리");
            break;
        }
        if (AILineCount >= 5)
        {
            printf("AI승리");
            break;
        }
        
    }

}