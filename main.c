#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <winuser.h>
#include <string.h>


void GotoXY(int X, int Y)
{
    COORD coord = {X, Y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame (int left_x, int left_y, int right_x, int right_y)
{
    GotoXY(left_x, left_y);

    printf("%c", '\311');
    for(int i = left_x + 1; i <= right_x - 1; i++)
    {
        printf("%c", '\315');
    }
    printf("%c", '\273');


    for(int i = left_y + 1; i <= right_y - 1; i++)
    {
        GotoXY(left_x, i);
        printf("%c", '\272');
        GotoXY(right_x, i);
        printf("%c", '\272');
    }

    GotoXY(left_x, right_y);
    printf("%c", '\310');
    for(int i = left_x + 1; i <= right_x - 1; i++)
    {
        printf("%c", '\315');
    }
    printf("%c", '\274');
}

void title_page()
{
    system("cls");
    frame(1, 1, 80, 25);
    GotoXY(20,2);
    printf("National Technical University of Ukraine\n");
    GotoXY(20,3);
    printf("\"Kyiv Polytechnic Institute named after\n");
    GotoXY(33,4);
    printf("Igor Sikorsky\"\n");
    GotoXY(25,6);
    printf("Faculty of Applied Mathematics\n");
    GotoXY(18,7);
    printf("Department of system programming and specialized\n");
    GotoXY(33,8);
    printf("computer systems\n");
    GotoXY(34,10);
    printf("Lab work N6\n");
    GotoXY(28,12);
    printf("Subject: Programming\n");
    GotoXY(33,14);
    printf("Topic: Strings\n");
    GotoXY(28,17);
    printf("Press ENTER to continue:\n");
    GotoXY(56,22);
    printf("Group: KV-33\n");
    GotoXY(56,23);
    printf("Done by: Polishchuk M.I.\n");
    GotoXY(56,24);
    printf("Grade:\n");
    GotoXY(35,24);
    printf("Kyiv 2023\n");
    getch();
    system("cls");
    menu();
}

const int modes_number = 4;
char menu_items[4][20] = {"1.Title Page", "2.Requirements", "3.Start", "4.Exit"};

void Requirements_page()
{
    system("cls");
    frame(1, 1, 80, 25);
    GotoXY(34,7);
    printf("Variant 18\n");
    GotoXY(2,2);
    printf("Formulation of the problem:\n");
    GotoXY(2,3);
    printf("Perform actions with strings according to the variant.\n");
    GotoXY(5,9);
    printf("18. A non-empty text with a length of up to 255 characters is specified.\n");
    GotoXY(5,10);
    printf("Find all the words of the text that contain the largest number of Latin\n");
    GotoXY(28,11);
    printf("vowels (a, e, i, o, u, y).\n");
    GotoXY(28,16);
    printf("Press ENTER to continue:\n");
    GotoXY(35,24);
    printf("Kyiv 2023\n");
    getch();
    system("cls");
    menu();
}

void Start()
{
        system("cls");
        fflush(stdin);
        char string[256];
        int cnt_vowel;
        int max_vowel;
        int flag;
        int length;
        do
        {
            system("cls");
            fflush(stdin);
            printf("Input text(up to 255 characters long):");
            gets(string);
            length = strlen(string);
            if(length >= 255)
            {
                printf("Incorrect number of symbols.Try again.");
                Sleep(2000);
            }
        }
        while(length >= 255 || length == 0);

        printf("\nYour text:\n");
        puts(string);

        flag = 0;
        max_vowel = 0;
        cnt_vowel = 0;
        string[length] = ' ';
        for(int i = 0; i <= length; i++)
        {
            if(string[i] != ' ' && flag == 0)
            {
                flag = 1;
            }

            else if(string[i] == ' ' && flag == 1)
            {
                flag = 0;
            }

            if(tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u' || tolower(string[i]) == 'y')
            {
                cnt_vowel++;
            }
            if(string[i] == ' ' && flag == 0)
            {
                if(cnt_vowel > max_vowel)
                {
                    max_vowel = cnt_vowel;
                }
                cnt_vowel = 0;
            }
        }

        if(max_vowel == 0)
        {
            printf("There is no vowel in the text.");
            getch();
            menu();
        }

        short ind_first, ind_last;
        printf("Max vowel = %d", max_vowel);
        printf("\nWords with max number of vowel is: ");
        for(int i = 0; i <= length; i++)
        {
            if(string[i] != ' ' && flag == 0)
            {
                flag = 1;
                ind_first = i;
            }

            else if(string[i] == ' ' && flag == 1)
            {
                flag = 0;
                ind_last = i;
            }

            if(tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u' || tolower(string[i]) == 'y')
            {
                cnt_vowel++;
            }

            if(string[i] == ' ' && flag == 0)
            {
                if(cnt_vowel == max_vowel)
                {

                    while(ind_first <= ind_last)
                    {
                        string[ind_first];
                        printf("%c", string[ind_first]);
                        ind_first++;
                    }
                }
                cnt_vowel = 0;
            }
        }
        getch();
        menu();
}

void menu()
{
    while(true)
    {
        int current_mode;
        system("cls");
        frame(1, 1, 80, 25);
        GotoXY(35,24);
        printf("Kyiv 2023\n");
        GotoXY(35,4);
        printf("MAIN MENU");
        for (int i = 0; i < 4; i++)
        {
            GotoXY(34, 10 + i);
            printf("%s\n", menu_items[i]);
        }
        GotoXY(20,17);
        printf("Input modes number and press ENTER:");
        scanf("%d", &current_mode);
        switch(current_mode)
        {
        case 1:
            title_page();
            break;

        case 2:
            Requirements_page();
            break;

        case 3:
            Start();
            break;

        case 4:
            system("cls");
            exit(1);
        default:
            GotoXY(20,19);
            printf("Invalid value entered! Please try again.");
            Sleep(2000);
            fflush(stdin);
        }
    }
}

int main()
{
    menu();
    return 0;
}
