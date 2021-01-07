#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>

void mgotoxy(int x,int y)
{
    COORD p= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void tab()
{
    int x_tab;

    for(x_tab=0; x_tab<26; x_tab++)
    {
        mgotoxy(0,x_tab);
        printf("%c",219);
    }
    for(x_tab=0; x_tab<50; x_tab++)
    {
        mgotoxy(x_tab,0);
        printf("%c",219);
    }
    for(x_tab=0; x_tab<26; x_tab++)
    {
        mgotoxy(50,x_tab);
        printf("%c",219);
    }
    for(x_tab=0; x_tab<51; x_tab++)
    {
        mgotoxy(x_tab,26);
        printf("%c",219);
    }
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}

void nave (int x_nave, int y_nave)
{
    int i, j;
    char n[2][3]= {{' ',178,' '},
        {178,178,178}
    };

    gotoxy(x_nave, y_nave);

    for (i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%c", n[i][j]);
        }
        gotoxy(x_nave, y_nave+1);
    }
}

void invader (int x_invader, int y_invader)
{
    int i, j;
    char n[2][3]= {{178,178,178},
        {' ',178,' '}
    };

    gotoxy(x_invader, y_invader);

    for (i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%c", n[i][j]);
        }
        gotoxy(x_invader, y_invader+1);
    }
}

void apagar(int x_apagador, int y_apagador)
{
    int i, j;
    gotoxy(x_apagador, y_apagador);

    for (i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf(" ");
        }
        y_apagador++;
        gotoxy(x_apagador, y_apagador);
    }
}

void protecao(int x_protecao, int y_protecao)
{
    int i=0, j=0, x0;
    x0=x_protecao;
    char p[3][7]= {{178,178,178,178,178,178,178},
        {178,' ',' ',' ',' ',' ',178},
        {178,' ',' ',' ',' ',' ',178}
    };

    for(i=0; i<3; i++)
    {
        for(j=0; j<7; j++)
        {
            gotoxy(x_protecao,y_protecao);
            x_protecao++;
            printf("%c", p[i][j]);
        }
        gotoxy(x_protecao,y_protecao++);
        x_protecao=x0;
    }
}

void bala(x_bala, y_bala)
{
    int a=0;
    int x_ab, y_ab;
    int i, j;

         do{
            gotoxy(x_bala,y_bala);
            printf("x");
            Sleep(100);
            x_ab=x_bala;
            y_ab=y_bala;
            gotoxy(x_ab, y_ab);

    for (i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf(" ");
        }
        y_ab--;
        gotoxy(x_ab, y_ab);
    }
            gotoxy(x_bala,y_bala--);
            a++;
         }while(a<19);

}

int main()
{
    //system("MODE con: cols=51 lines=27");
    int x_nave=24, y_nave=24,x_invader=2,y_invader=3,i, x_apagador=24,y_apagador=24, a=0;
    int x_protecao=10, y_protecao=20, x_bala, y_bala, x_ab, y_ab;
    char c;

    tab();
    gotoxy(x_invader,y_invader);
    protecao(x_protecao,y_protecao);//PROTEÇÃO PARA A NAVE
    x_protecao=35;
    protecao(x_protecao,y_protecao);

    for(a=0; a<3; a++)
    {
        for(i=0; i<8; i++)
        {
            x_invader = x_invader+5;
            invader(x_invader,y_invader);

        }
        if(a == 0)
        {
            x_invader = 4;
        }
        if(a == 1)
        {
            x_invader = 1;
        }

        y_invader = y_invader+3;
        gotoxy(x_invader,y_invader);

    }

    do
    {
        nave (x_nave,y_nave);
        c=getch();

        switch(c)
        {
        case 75:
            apagar(x_apagador,y_apagador);
            gotoxy(x_apagador,y_apagador); //SETA ESQUERDA
            x_apagador = x_nave;
            apagar(x_apagador, y_apagador);
            x_nave=x_nave-1;
            if(x_nave==1)
                x_nave=x_nave+1;
            break;

        case 77:
            apagar(x_apagador,y_apagador);
            gotoxy(x_apagador,y_apagador); //SETA DIREITA
            x_apagador = x_nave;
            apagar(x_apagador, y_apagador);
            x_nave=x_nave+1;
            if(x_nave==49)
                x_nave=x_nave-1;
            break;

        case 32:
            x_bala=x_nave+1;
            y_bala=y_nave-1;
            bala(x_bala,y_bala);
            break;


        }
    }
    while(1);
    return 0;
}
