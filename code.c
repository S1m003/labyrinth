#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char character();
void efforts(char gender);
void Tutorial(char gender);
void Easy(char gender,int level);
void Normal(char gender,int level);
void Hard(char gender,int level);
int moviment(char matrice[][60],int position_x,int position_y,int dim,char gender,int levels,int secret_x,int secret_y,
             int start_teleport_1_x,int start_teleport_1_y,int end_teleport_1_x,int end_teleport_1_y,
             int start_teleport_2_x,int start_teleport_2_y,int end_teleport_2_x,int end_teleport_2_y);

int main()
{
/*
    char alpha;
    for(int i=0;i<300;i++)
    {
        alpha=i;
        printf("%d-%c ",i,alpha);
    }
*/

    char gender;

    printf("escape the labirinth");
    printf("choosen character: %c\n",gender=character());

    efforts(gender);

/*
    10 - tutorial
    20/30 - normal
    40/50 - difficult
*/

    return 0;
}

char character()
{
    char g[3],gender;
    int flag=0;
    printf("\n\nplease choose your character:\n\t\tXX-female \t\tXY-male \t\tYY-other\n");
    printf("\t\t\t");scanf("%s",g);
    while(flag==0)
    {
        if(g[0]=='X'||g[0]=='x')
        {
            if(g[1]=='X'||g[1]=='x')
            {
                gender=12;
                flag=1;
            }
            else if(g[1]=='Y'||g[1]=='y')
            {
                gender=11;
                flag=1;
            }
            else
            {
                printf("please, insert only the letters writen above.");
                scanf("%s",g);
            }
        }else if(g[0]=='Y'||g[0]=='y')
        {
            gender=15;
            flag=1;
        }
        else
        {
            printf("please, insert only the letters writen above.");
            scanf("%s",g);
        }
    }
    return gender;
}

void efforts(char gender)
{
    char complexity;
    printf("\nplease choose the difficulty:\n0-tutorial \nE-easy \t\tN-normal \t\tH-hard\n");
    scanf("%c",&complexity);
    scanf("%c",&complexity);
    while(complexity!='e'&&complexity!='n'&&complexity!='h'&&complexity!='E'&&complexity!='N'&&complexity!='H'&&complexity!='0')
    {
        printf("please insert only the letters/number above: ");
                scanf("%c",&complexity);
                scanf("%c",&complexity);
    }
    switch(complexity)
    {
        case '0':
            Tutorial(gender);
            break;
        case 'e':
            Easy(gender,0);
            break;
        case 'E':
            Easy(gender,0);
            break;
        case 'n':
            Normal(gender,1);
            break;
        case 'N':
            Normal(gender,1);
            break;
        case 'h':
            Hard(gender,1);
            break;
        case 'H':
            Hard(gender,1);
            break;
        default:
            break;
    }
}

void Tutorial(char gender)
{
    char build[60][60];
    const char bloc=219;
    int dimension=10,p_x,p_y,flag;
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<60;j++)
            build[i][j]=0;
    }
    for(int i=0;i<dimension;i++)
    {
        build[i][0]='.';
        for(int j=0;j<dimension;j++)
        {
            build[0][j]='.';
            build[0][dimension+j]='.';
        }
    }
    build[0][1]='I';
    build[1][0]='I';
    build[0][5]='V';
    build[5][0]='V';
    build[0][10]='X';
    build[10][0]='X';
    build[0][15]='|';
    build[0][20]='X';
    for(int i=0;i<dimension;i++)
    {
        if(i==1)
            continue;
        for(int j=0;j<dimension;j++)
        {
            build[i+1][j+3]=219; //219
        }
    }
    build[dimension/2][dimension+8]='W';
    build[dimension/2][dimension+9]=17;
    build[dimension/2][dimension+11]=16;
    build[dimension/2][dimension+12]='E';
    build[dimension/2-1][dimension+10]=30;
    build[dimension/2-2][dimension+10]='N';
    build[dimension/2+1][dimension+10]=31;
    build[dimension/2+2][dimension+10]='S';
    build[2][1]=gender;
    p_x=2;
    p_y=1;
    build[2][2]=16;
    build[2][13]=16;
    build[2][14]=3;
    for(int i=0;i<dimension+2;i++)
    {
        printf("\n");
        for(int j=0;j<dimension+13;j++)
        {
            if(i>0&&i<dimension+1&&j>2&&j<dimension+3&&i!=2)
            {
                printf("%c%c",build[i][j],bloc);
            }
            else
                printf("%c ",build[i][j]);
        }
    }
    printf("\n");
    printf("insert a sequence of letters like: enneeeeeeeeeeeess\n");
    flag=moviment(build,p_x,p_y,dimension,gender,0,0,0,0,0,0,0,0,0,0,0);
    if(flag>0)
    {
        printf("\ndo you wanna play?\n\t\t0-yes\t\t1-no\n\t\t");
        scanf("%d",&flag);
        if(flag==0)
            efforts(gender);
    }
}

void Easy(char gender,int level)
{
    char build[60][60];
    const char bloc=219;
    int dimension=10,p_x,p_y,flag;
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<60;j++)
        build[i][j]=0;
    }
    for(int i=0;i<dimension;i++)
    {
        build[i][0]='.';
        build[dimension+i][0]='.';
        for(int j=0;j<dimension;j++)
        {
            build[0][j]='.';
            build[0][dimension+j]='.';
        }
    }
    build[0][1]='I';
    build[1][0]='I';
    build[0][5]='V';
    build[5][0]='V';
    build[0][10]='X';
    build[10][0]='X';
    build[0][15]='|';
    build[0][20]='X';
    build[dimension/2+2][dimension+8]='W';
    build[dimension/2+2][dimension+9]=17;
    build[dimension/2+2][dimension+11]=16;
    build[dimension/2+2][dimension+12]='E';
    build[dimension/2+1][dimension+10]=30;
    build[dimension/2][dimension+10]='N';
    build[dimension/2+3][dimension+10]=31;
    build[dimension/2+4][dimension+10]='S';
    if(level==0)
    {
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i==8&&j>2&&j<9)||(j==2&&i<9))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[1][5]=gender;
        p_x=1;
        p_y=5;
        build[2][5]=31;
        build[11][11]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!((i==11&&j>5&&j<12)||(j==5&&i<12)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==1)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i==2&&j<4)||(i==2&&j>5)||(i==3&&j>2&&j<7))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[5][1]=gender;
        p_x=5;
        p_y=1;
        build[5][2]=16;
        build[5][13]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!((i==5&&j<7)||(i==5&&j>8)||(i==6&&j>5&&j<10)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==2)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i==4&&j>1)||(i>4&&i<9&&j==2)||(i>7&&j==1)||(i==9&&j==0))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[12][1]=gender;
        p_x=12;
        p_y=1;
        build[12][2]=16;
        build[7][13]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!((i==7&&j>4)||(i>7&&i<12&&j==5)||(i>10&&j==4)||(i==12&&j==3)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==3)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i>3&&(j==2||j==5))||
                   (i==4&&(j==1||j==6))||
                   (i>2&&i<5&&j==0)||
                   (i==2&&j<6)||
                   (i==1&&j>4&&j<8)||
                   (i>1&&i<5&&j==7))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[14][5]=gender;
        p_x=14;
        p_y=5;
        build[13][5]=30;
        build[13][8]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+5;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   ((i>6&&(j==5||j==8))||(i==7&&(j==4||j==9))||(i>5&&i<8&&j==3)||(i==5&&j<9)||(i==4&&j>7&&j<11)||(i>4&&i<8&&j==10)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==4)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i==1&&((j>0&&j<4)||(j>4&&j<8)||j>8))||
                   (i==8&&(j<2||(j>2&&j<6)||j>6))||
                   ((i>1&&i<8)&&(j==1||j==3||j==5||j==7||j==9)))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[11][1]=gender;
        p_x=11;
        p_y=1;
        build[11][2]=16;
        build[4][13]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   ((i==4&&((j>3&&j<7)||(j>7&&j<11)||j>11))||(i==11&&(j<5||(j>5&&j<9)||j>9))||((i>4&&i<11)&&(j==4||j==6||j==8||j==10||j==12))))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==5)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i>0&&i<9&&j==0)||
                   ((i<2||i>7)&&j==1)||
                   (((i>1&&i<8)||i==9)&&j==2)||
                   ((i<3||i>6)&&j==3)||
                   (i==0&&j>2&&j<9)||
                   (i==9&&j>5&&j<9)||
                   (i>3&&i<7&&j==4)||
                   (((i>0&&i<4)||(i>5))&&j==5)||
                   (i>4&&i<8&&j==7)||
                   (i==3&&j>6&&j<9)||
                   (i>0&&i<9&&j==9)||
                   ((i==2||i==7)&&j==6)||
                   ((i==1||i==8)&&j==8))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[1][4]=gender;
        p_x=1;
        p_y=4;
        build[2][4]=31;
        build[13][8]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   ((i>3&&i<12&&j==3)||((i<5||i>10)&&j==4)||(((i>4&&i<11)||i==12)&&j==5)||
                    ((i<6||i>9)&&j==6)||(i==3&&j>5&&j<12)||(i==12&&j>8&&j<12)||(i>6&&i<10&&j==7)||
                    (((i>3&&i<7)||(i>8))&&j==8)||(i>7&&i<11&&j==10)||(i==6&&j>9&&j<12)||(i>3&&i<12&&j==12)||((i==5||i==10)&&j==9)||((i==4||i==11)&&j==11)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==6)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i<4&&j==1)||
                   (i==3&&j>1&&j<8)||
                   (i>3&&i<8&&(j==7||j==0))||
                   (i==8&&j<4)||
                   (i==9&&j>2&&j<8))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[1][4]=gender;
        p_x=1;
        p_y=4;
        build[2][4]=31;
        build[13][10]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   ((i<7&&j==4)||(i==6&&j>4&&j<11)||(i>6&&i<11&&(j==10||j==3))||(i==11&&j<7)||(i==12&&j>5&&j<11)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==7)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i==5&&(j<2||j==9))||
                   ((i==4||i==6)&&((j>0&&j<3)||j>7))||
                   ((i==3||i==7)&&((j>1&&j<4)||(j>6&&j<9)))||
                   ((i==2||i==8)&&(j>2&&j<8))||
                   ((i>3&&i<7)&&(j==3||j==7))||
                   ((i>2&&i<9)&&j==5))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[8][1]=gender;
        p_x=8;
        p_y=1;
        build[8][2]=16;
        build[8][13]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   ((i==8&&(j<5||j==12))||((i==7||i==9)&&((j>3&&j<6)||j>10))||((i==6||i==10)&&((j>4&&j<7)||(j>9&&j<12)))||
                    ((i==5||i==11)&&(j>5&&j<11))||((i>6&&i<10)&&(j==6||j==10))||((i>5&&i<12)&&j==8)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==8)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if(((i==0||i==9)&&(j>2&&j<7))||
                   ((i==1||i==8)&&((j>0&&j<4)||(j>5&&j<9)))||
                   ((i>2&&i<7)&&(j==0||j==9))||
                   (((i>1&&i<4)||(i>5&&i<8))&&(j==1||j==8))||
                   (i==0&&j==0)||
                   (i==5&&(j>0&&j<6))||
                   (i==4&&(j>3&&j<9)))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[8][3]=gender;
        p_x=8;
        p_y=3;
        build[7][3]=30;
        build[9][3]=31;
        build[7][12]=3;
        build[3][3]=5;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   (((i==3||i==12)&&(j>5&&j<10))||((i==4||i==11)&&((j>3&&j<7)||(j>8&&j<12)))||((i>5&&i<10)&&(j==3||j==12))||
                   (((i>4&&i<7)||(i>8&&i<11))&&(j==4||j==11))||(i==3&&j==3)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        printf("if you wana go through the secret passage(_%c_%c) (position:(8,5) you'll need the key(%c)\n"
               "once you get it, you can pass through the secret passage\n"
               "you can write all the moves (both to reach the key and to reach the heart) in 1 line/string\n"
               "or write them in differt lines/string, first to reach the key and second to reach the heart\n\n",bloc,bloc,build[3][3]);
        level=moviment(build,p_x,p_y,dimension,gender,level,8,5,0,0,0,0,0,0,0,0);
    }
    if(level==9)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((i==0&&(j==0||j==9))||
                   ((i==1||i==9)&&(j<2||j>7))||
                   ((i==2||i==8)&&((j>0&&j<3)||(j>6&&j<9)))||
                   ((i==3||i==7)&&((j>1&&j<4)||(j>5&&j<8)))||
                   ((i==4||i==6)&&(j>2&&j<7))||
                   (i==5&&((j>3&&j<6)||(j>6)))||
                   ((i>2&&i<8)&&j==1))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[8][4]=gender;
        p_x=8;
        p_y=4;
        build[7][4]=30;
        build[9][4]=31;
        build[8][10]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                   ((i==3&&(j==3||j==12))||((i==4||i==12)&&(j<5||j>10))||((i==5||i==11)&&((j>3&&j<6)||(j>9&&j<12)))||
                    ((i==6||i==10)&&((j>4&&j<7)||(j>8&&j<11)))||((i==7||i==9)&&(j>5&&j<10))||(i==8&&((j>6&&j<9)||(j>9)))||((i>5&&i<11)&&j==4)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level==10)
    {
        for(int i=1;i<dimension+4;i++)
        {
            for(int j=1;j<dimension+5;j++)
            build[i][j]=0;
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                if((((i>0&&i<5)||(i>5&&i<9))&&j==0)||
                   ((i==1||i==8)&&(j==1||j==8))||
                   ((i==4||i==6)&&(j>0&&j<3))||
                   (i==0&&(j>0&&j<9))||
                   ((i==3||i==7)&&j>1)||
                   (i==9&&(j>0&&j<7))||
                   (i==8&&(j>5&&j<8))||
                   ((i>3&&i<7)&&(j>4&&j<7))||
                   (i==5&&((j>2&&j<5)||j==8))||
                   ((i>0&&i<3)&&j==9)||
                   (i==5&&j==7))
                    continue;
                build[i+3][j+3]=219; //219
            }
        }
        build[8][6]=gender;
        p_x=8;
        p_y=6;
        build[8][7]=16;
        build[8][11]=3;
        printf("\n\t\t\t\t\t\tlivello E.%d",level);
        for(int i=0;i<dimension+4;i++)
        {
            printf("\n");
            for(int j=0;j<dimension+13;j++)
            {
                if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!
                    ((((i>3&&i<8)||(i>8&&i<12))&&j==3)||((i==4||i==11)&&(j==4||j==11))||((i==7||i==9)&&(j>3&&j<6))||(i==3&&(j>3&&j<12))||
                    ((i==6||i==10)&&j>4)||(i==12&&(j>3&&j<10))||(i==11&&(j>8&&j<11))||((i>6&&i<10)&&(j>7&&j<10))||
                    (i==8&&((j>5&&j<8)||j==11))||((i>3&&i<6)&&j==12)||(i==8&&j==12)))
                {
                    printf("%c%c",build[i][j],bloc);
                }
                else
                    printf("%c ",build[i][j]);
            }
        }
        printf("\n");
        printf("\nhint?\n\t\t0-yes\t\t1-no\n\t\t\t");
        scanf("%d",&flag);
        if(flag!=0&&flag!=1)
        {
            while(flag!=0&&flag!=1)
            {
                printf("please insert only those numbers above:  ");
                scanf("%d",&flag);
            }
        }
        if(flag==0)
            printf("la parete a sinistra del cuore NON e' una vera parete (e' una tenda...?), puo' essere tranquillamente attraversata\n"
                   "la parete a destra invece e' una vera parete\n");
        printf("\n");
        level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
    }
    if(level>10)
    {
        printf("\ndo you wanna play again?\n\t\t0-yes\t\t1-no\n\t\t");
        scanf("%d",&flag);
        if(flag==0)
            efforts(gender);
    }
}
void Normal(char gender,int level)
{
    char io=2;
    char build[60][60];
    const char bloc=219;
    int dimension,p_x,p_y,flag;
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<60;j++)
        build[i][j]=0;
    }
    printf("choose the dimension:\n\t\t0-20\t\t1-30\n\t\t");
    scanf("%d",&flag);
    if(flag!=0&&flag!=1&&flag!=20&&flag!=30)
    {
        while(flag!=0&&flag!=1&&flag!=20&&flag!=30)
        {
            printf("please insert only the one of the four number above: ");
            scanf("%d",&flag);
        }
    }
    if(flag==0||flag==20)
    {
        dimension=20;
        for(int i=0;i<dimension;i++)
        {
            build[i][0]='.';
            build[dimension+i][0]='.';
            for(int j=0;j<dimension;j++)
            {
                build[0][j]='.';
                build[0][dimension+j]='.';
            }
        }
        build[0][1]='I';
        build[0][5]='V';
        build[0][10]='X';
        build[1][10]='1';
        build[0][15]='|';
        build[0][20]='X';
        build[1][20]='2';
        build[0][25]='|';
        build[0][30]='X';
        build[1][30]='3';
        build[1][0]='I';
        build[5][0]='V';
        build[10][0]='X';
        build[10][1]='1';
        build[15][0]='|';
        build[20][0]='X';
        build[20][1]='2';
        build[dimension/2+2][dimension+8]='W';
        build[dimension/2+2][dimension+9]=17;
        build[dimension/2+2][dimension+11]=16;
        build[dimension/2+2][dimension+12]='E';
        build[dimension/2+1][dimension+10]=30;
        build[dimension/2][dimension+10]='N';
        build[dimension/2+3][dimension+10]=31;
        build[dimension/2+4][dimension+10]='S';
        printf("selezionare il livello: ");
        scanf("%d",&level);
        if(level==1)
        {
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(((i>6&&i<13)&&(j==0||j==19))||
                       ((i==0||i==19)&&(j>6&&j<13))||
                       (((i>4&&i<8)||(i>11&&i<15))&&(j==1||j==18))||
                       (((i>2&&i<6)||(i>13&&i<17))&&(j==2||j==17))||
                       ((i==1||i==18)&&((j>4&&j<8)||(j>11&&j<15)))||
                       ((i==2||i==17)&&((j>2&&j<6)||(j>13&&j<17)))||
                       (i==10&&((j>0&&j<3)||(j>6&&j<11)))||
                       (i==9&&((j>8&&j<13)||(j>16&&j<19)))||
                       ((i==3||(i>6&&i<13)||i==16)&&(j==3||j==16))||
                       ((i==3||i==16)&&(j>6&&j<13))||
                       (((i>5&&i<8)||(i>11&&i<14))&&(j==4||j==15))||
                       (((i>4&&i<7)||(i>12&&i<15))&&(j==5||j==14))||
                       (((i>3&&i<6)||(i>7&&i<12)||(i>13&&i<16))&&(j==6||j==13))||
                       ((i==6||i==13)&&(j>7&&j<12))||
                       ((i==4||(i>6&&i<9)||(i>10&&i<13)||i==15)&&(j==7||j==12))||
                       ((i==7||i==12)&&(j==8||j==11))||
                       ((i>3&&i<6)&&j==10)||
                       ((i>13&&i<16)&&j==9))
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[13][3]=gender;
            p_x=13;
            p_y=3;
            build[12][3]=30;
            build[13][4]=16;
            build[14][3]=31;
            build[12][13]=3;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                       ((i>9&&i<16)&&(j==3||j==22))||((i==3||i==22)&&(j>9&&j<16))||(((i>7&&i<11)||(i>14&&i<18))&&(j==4||j==21))||
                       (((i>5&&i<9)||(i>16&&i<20))&&(j==5||j==20))||((i==4||i==21)&&((j>7&&j<11)||(j>14&&j<18)))||
                       ((i==5||i==20)&&((j>5&&j<9)||(j>16&&j<20)))||(i==13&&((j>3&&j<6)||(j>9&&j<14)))||(i==12&&((j>11&&j<16)||(j>19&&j<22)))||
                       ((i==6||(i>9&&i<16)||i==19)&&(j==6||j==19))||((i==6||i==19)&&(j>9&&j<16))||(((i>8&&i<11)||(i>14&&i<17))&&(j==7||j==18))||
                       (((i>7&&i<10)||(i>15&&i<18))&&(j==8||j==17))||(((i>6&&i<9)||(i>10&&i<15)||(i>16&&i<19))&&(j==9||j==16))||
                       ((i==9||i==16)&&(j>10&&j<15))||((i==7||(i>9&&i<12)||(i>13&&i<16)||i==18)&&(j==10||j==15))||((i==10||i==15)&&(j==11||j==14))||
                       ((i>6&&i<9)&&j==13)||((i>16&&i<19)&&j==12)))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
        }
        if(level==2)
        {
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(((i==1||i==18)&&(j>0&&j<19))||
                       ((i>1&&i<18)&&(j==1||j==18))||
                       (i>15&&i<18&&j==9)||
                       ((i==4||i==15)&&(j>3&&j<16))||
                       ((i>3&&i<16)&&(j==4||j==15))||
                       (i==10&&j>4&&j<7)||
                       ((i==7||i==12)&&(j>6&&j<13))||
                       ((i>6&&i<13)&&(j==7||j==12))||
                       (i==10&&j>8&&j<11)||
                       (i==0&&j==0)||
                       (i==0&&j==10)||
                       (i==9&&j>9&&j<12)
                       )
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[2][13]=gender;
            p_x=2;
            p_y=13;
            build[3][13]=31;
            build[13][12]=3;
            build[3][3]=5;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                       ((i==4||i==21)&&(j>3&&j<22))||((i>4&&i<21)&&(j==4||j==21))||(i>18&&i<21&&j==12)||((i==7||i==18)&&(j>6&&j<19))||
                       ((i>6&&i<19)&&(j==7||j==18))||(i==13&&j>7&&j<10)||((i==10||i==15)&&(j>9&&j<16))||((i>9&&i<16)&&(j==10||j==15))||
                       (i==3&&j==3)||(i==3&&j==13)||(i==13&&j==12)))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
        }
        if(level==3)
        {
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if((i<12&&j==0)||
                       (i==19&&(j>3&&j<12))||
                       (((i>0&&i<5)||(i>7&&i<16))&&j==19)||
                       (i==0&&((j>0&&j<5)||j>7))||
                       ((i>3&&i<6)&&(j>0&&j<5))||
                       ((i>14&&i<19)&&(j>3&&j<6))||
                       ((i>13&&i<16)&&(j>14&&j<19))||
                       ((i>0&&i<5)&&(j>13&&j<16))||
                       ((i>2&&i<7)&&j==5)||
                       ((i==14)&&(j>2&&j<7))||
                       ((i>12&&i<17)&&j==14)||
                       (i==5&&(j>12&&j<17))||
                       (((i>0&&i<4)||(i>5&&i<9))&&j==6)||
                       (i==13&&((j>0&&j<4)||(j>5&&j<9)))||
                       (((i>10&&i<14)||(i>15&&i<19))&&j==13)||
                       (i==6&&((j>10&&j<14)||(j>15&&j<19)))||
                       ((i==1||i==8)&&(j>6&&j<9))||
                       ((i>10&&i<13)&&(j==1||j==8))||
                       ((i==11||i==18)&&(j>10&&j<13))||
                       ((i>6&&i<9)&&(j==11||j==18))||
                       (i==9&&(j>7&&j<10))||
                       ((i>9&&i<12)&&j==9)||
                       (i==10&&(j>9&&j<12))||
                       ((i>7&&i<10)&&j==10)||
                       (i==1&&((j>0&&j<3)||j==4))||
                       ((i>14&&i<19)&&j==1)||
                       (i==18&&((j>14&&j<19)||(j>1&&j<4)))||
                       (((i>0&&i<3)||i==4||(i>15&&i<18))&&j==18)||
                       (i==9&&((j>1&&j<5)||(j>13&&j<17)))||
                       (i==10&&((j>2&&j<6)||(j>14&&j<18)))||
                       ((i>5&&i<9)&&j==3)||
                       ((i>10&&i<14)&&j==16)||
                       (i==11&&j==4)||
                       (i==8&&j==15))
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[4][5]=gender;
            p_x=4;
            p_y=5;
            build[3][5]=30;
            build[4][4]=17;
            build[20][4]=3;
            build[21][20]=5;
            build[4][7]=233;
            build[21][18]=233;
            build[11][18]=232;
            build[18][4]=232;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                       (i<15&&j==3)||(i==22&&(j>6&&j<15))||(((i>3&&i<8)||(i>10&&i<19))&&j==22)||(i==3&&((j>3&&j<8)||j>10))||((i>6&&i<9)&&(j>3&&j<8))||
                       ((i>17&&i<22)&&(j>6&&j<9))||((i>16&&i<19)&&(j>17&&j<22))||((i>3&&i<8)&&(j>16&&j<19))||((i>5&&i<10)&&j==8)||((i==17)&&(j>5&&j<10))||
                       ((i>15&&i<20)&&j==17)||(i==8&&(j>15&&j<20))||(((i>3&&i<7)||(i>8&&i<12))&&j==9)||(i==16&&((j>3&&j<7)||(j>8&&j<12)))||
                       (((i>13&&i<17)||(i>18&&i<22))&&j==16)||(i==9&&((j>13&&j<17)||(j>18&&j<22)))||((i==4||i==11)&&(j>9&&j<12))||
                       ((i>13&&i<16)&&(j==4||j==11))||((i==14||i==21)&&(j>13&&j<16))||((i>9&&i<12)&&(j==14||j==21))||(i==12&&(j>10&&j<13))||
                       ((i>12&&i<15)&&j==12)||(i==13&&(j>12&&j<15))||((i>10&&i<13)&&j==13)||(i==4&&((j>3&&j<6)||j==7))||((i>17&&i<22)&&j==4)||
                       (i==21&&(j>17&&j<22))||(((i>3&&i<6)||i==7||(i>18&&i<21))&&j==21)||(i==12&&((j>4&&j<8)||(j>16&&j<20)))||
                       (i==13&&((j>5&&j<9)||(j>17&&j<21)))||((i>8&&i<12)&&j==6)||((i>13&&i<17)&&j==19)||(i==14&&j==7)||(i==11&&j==18)))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,21,6,4,7,21,18,11,18,18,4);
        }
        if(level==4)
        {
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(
                       ((i==7||i==14)&&((j>4&&j<9)||(j>10&&j<15)))||
                       ((i>7&&i<14)&&(j==8||j==11))||
                       ((i>4&&i<7)&&(j==5||j==14))||
                       ((i>12&&i<17)&&(j==4||j==15))||
                       (i==4&&((j>2&&j<7)||(j>12&&j<17)))||
                       (((i>10&&i<14)||(i>15&&i<19))&&(j==3||j==16))||
                       (i==3&&((j>0&&j<4)||(j>5&&j<9)||(j>10&&j<14)||(j>15&&j<19)))||
                       ((i==11||i==18)&&((j>0&&j<3)||(j>16&&j<19)))||
                       ((i>0&&i<3)&&(j==1||j==8||j==11||j==18))||
                       (i==10&&(j<2||j>17))||
                       (i<2&&(j==0||j==19))||
                       ((i<2||i==8)&&j==9)||
                       ((i<2||i==13)&&j==10)
                        )
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[21][4]=gender;
            p_x=21;
            p_y=4;
            build[21][5]=16;
            build[21][21]=3;
            build[3][3]=5;
            build[11][12]=233;
            build[16][13]=233;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                       ((i==10||i==17)&&((j>7&&j<12)||(j>13&&j<18)))||((i>10&&i<17)&&(j==11||j==14))||((i>7&&i<10)&&(j==8||j==17))||
                       ((i>15&&i<20)&&(j==7||j==18))||(i==7&&((j>5&&j<10)||(j>15&&j<20)))||(((i>13&&i<17)||(i>18&&i<22))&&(j==6||j==19))||
                       (i==6&&((j>3&&j<7)||(j>8&&j<12)||(j>13&&j<17)||(j>18&&j<22)))||((i==14||i==21)&&((j>3&&j<6)||(j>19&&j<22)))||
                       ((i>3&&i<6)&&(j==4||j==11||j==14||j==21))||(i==13&&(j<5||j>20))||(i<5&&(j==3||j==22))||((i<5||i==11)&&j==12)||((i<5||i==16)&&j==13)))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,11,12,16,13,0,0,0,0);
        }
        if(level==5)
        {
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(
                       ((i>0&&i<9)&&(j==1||j==8))||
                       ((i==1||i==8)&&(j>1&&j<8))||
                       ((i==3||i==6)&&(j>2&&j<7))||
                       ((i>3&&i<6)&&(j==3||j==6))||

                       (i==2&&j==5)||
                       ((i==5||i==9)&&j==4)||

                       ((i==10||i==19)&&(j>2&&j<7))||
                       ((i>12&&i<17)&&(j==0||j==9))||
                       ((i==11||i==18)&&((j>0&&j<4)||(j>5&&j<9)))||
                       (((i>11&&i<14)||(i>15&&i<18))&&(j==1||j==8))||
                       (i==14&&j==10)||

                       ((i==1||i==8)&&((j>9&&j<12)||(j>16&&j<19)))||
                       ((i==2||i==7)&&((j>10&&j<13)||(j>15&&j<18)))||
                       ((i==3||i==6)&&((j>11&&j<14)||(j>14&&j<17)))||
                       ((i>3&&i<6)&&(j>12&&j<16))||
                       ((i==0||i==9)&&j>17)||
                       (i==9&&j==10)||
                       (i==1&&j==9)||

                       ((i==11||i==18)&&(j>10&&j<19))||
                       ((i>11&&i<18)&&(j==11||j==18))||
                       ((i==13||i==16)&&(j>12&&j<17))||
                       ((i>13&&i<16)&&(j==13||j==16))||
                       (i==15&&j==14)
                       )
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[8][7]=gender;
            p_x=8;
            p_y=7;
            build[18][17]=3;
            build[12][22]=5;
            build[12][13]=233;
            build[21][4]=233;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                       ((i>3&&i<12)&&(j==4||j==11))||((i==4||i==11)&&(j>4&&j<11))||((i==6||i==9)&&(j>5&&j<10))||((i>6&&i<9)&&(j==6||j==9))||(i==5&&j==8)||
                       ((i==8||i==12)&&j==7)||((i==13||i==22)&&(j>5&&j<10))||((i>15&&i<20)&&(j==3||j==12))||((i==14||i==21)&&((j>3&&j<7)||(j>8&&j<12)))||
                       (((i>14&&i<17)||(i>18&&i<21))&&(j==4||j==11))||(i==17&&j==13)||((i==4||i==11)&&((j>12&&j<15)||(j>19&&j<22)))||
                       ((i==5||i==10)&&((j>13&&j<16)||(j>18&&j<21)))||((i==6||i==9)&&((j>14&&j<17)||(j>17&&j<20)))||((i>6&&i<9)&&(j>15&&j<19))||
                       ((i==3||i==12)&&j>20)||(i==12&&j==13)||(i==4&&j==12)||((i==14||i==21)&&(j>13&&j<22))||((i>14&&i<21)&&(j==14||j==21))||
                       ((i==16||i==19)&&(j>15&&j<20))||((i>16&&i<19)&&(j==16||j==19))||(i==18&&j==17)))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,12,13,21,4,0,0,0,0);
        }
        if(level==6)
        {
            printf("\nworking progress... %c\n",io);
            efforts(gender);
            /*
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ())
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[][]=gender;
            p_x=;
            p_y=;
            build[][]=16;
            build[][]=3;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                                                                   ))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
            */
        }
        if(level==7)
        {
            printf("\nworking progress... %c\n",io);
            efforts(gender);
            /*
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ())
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[][]=gender;
            p_x=;
            p_y=;
            build[][]=16;
            build[][]=3;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                                                                   ))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
            */
        }
        if(level==8)
        {
            printf("\nworking progress... %c\n",io);
            efforts(gender);
            /*
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ())
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[][]=gender;
            p_x=;
            p_y=;
            build[][]=16;
            build[][]=3;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                                                                   ))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
            */
        }
        if(level==9)
        {
            printf("\nworking progress... %c\n",io);
            efforts(gender);
            /*
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ())
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[][]=gender;
            p_x=;
            p_y=;
            build[][]=16;
            build[][]=3;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                                                                   ))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
            */
        }
        if(level==10)
        {
            printf("\nworking progress... %c\n",io);
            efforts(gender);
            /*
            for(int i=2;i<dimension+4;i++)
            {
                for(int j=2;j<dimension+5;j++)
                build[i][j]=0;
            }
            for(int i=0;i<dimension;i++)
            {
                for(int j=0;j<dimension;j++)
                {
                    if(()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ()||
                       ())
                        continue;
                    build[i+3][j+3]=219; //219
                }
            }
            build[][]=gender;
            p_x=;
            p_y=;
            build[][]=16;
            build[][]=3;
            printf("\n\t\t\t\t\t\tlivello N.0.%d",level);
            for(int i=0;i<dimension+4;i++)
            {
                printf("\n");
                for(int j=0;j<dimension+13;j++)
                {
                    if((i>2&&i<dimension+3&&j>2&&j<dimension+3)&&!(
                                                                   ))
                    {
                        printf("%c%c",build[i][j],bloc);
                    }
                    else
                        printf("%c ",build[i][j]);
                }
            }
            printf("\n");
            level=moviment(build,p_x,p_y,dimension,gender,level,0,0,0,0,0,0,0,0,0,0);
            */
        }
        if(level>10)
        {
            printf("\ndo you wanna play again?\n\t\t0-yes\t\t1-no\n\t\t");
            scanf("%d",&flag);
            if(flag==0)
                efforts(gender);
        }
    }else
    {
        printf("\nworking progress... %c\n",io);
        efforts(gender);
    }
}
void Hard(char gender,int level)
{
    char io=1;
    printf("\nworking progress... %c\n",io);
    efforts(gender);
}

int moviment(char matrice[][60],int position_x,int position_y,int dim,char gender,int levels,int secret_x,int secret_y,
             int start_teleport_1_x,int start_teleport_1_y,int end_teleport_1_x,int end_teleport_1_y,
             int start_teleport_2_x,int start_teleport_2_y,int end_teleport_2_x,int end_teleport_2_y)
{
    int flag=0,vitae=3,istruzioni,morte,key=0;
    char cursore[100],object;
    const int x=position_x,y=position_y;
    printf("\nstarting position: %c \nyou have 4 lives(%c) to reach the heart\n",matrice[position_x][position_y],object=3);
    printf("insert all moves to reach the heart (every move, the arrow is like a hole): ");
    scanf("%s",cursore);
    while(flag==0&&vitae>0&&cursore[istruzioni]!='\0')
        {
            switch(cursore[istruzioni])
            {
            case 'n':
                position_x-=1;
                if(position_x<0)
                {
                     vitae-=1;
                     key=0;
                     printf("\nyou fell into water. you still have %d(%c)\n",vitae+1,object=3);
                     position_x=x;
                     position_y=y;
                     printf("posizione di partenza: %c\n",matrice[position_x][position_y]);
                     printf("new try, insert new moves: ");
                     scanf("%s",cursore);
                     istruzioni=-1;
                }
                if(matrice[position_x][position_y]==-37)
                    {vitae-=1;
                    key=0;
                    printf("\nyou Died. you still have %d(%c)\n",vitae+1,object=3);
                     position_x=x;
                     position_y=y;
                     printf("posizione di partenza: %c\n",matrice[position_x][position_y]);
                     printf("new try, insert new moves: ");
                     scanf("%s",cursore);
                     istruzioni=-1;}
                if(position_x==secret_x&&position_y==secret_y)
                {
                    if(key!=0||(secret_x==0&&secret_y==0))
                    {}
                    else
                    {
                        position_x+=1;
                        printf("\nunfortunatly you don't have the key(%c) to pass through",object=5);
                        printf("\nposizione di partenza: (%c%d,%c%d)",object=18,position_x,object=29,position_y);
                        printf("\nnew try, insert new moves: ");
                        scanf("%s",cursore);
                        istruzioni=-1;
                    }
                }
                if((position_x==start_teleport_1_x&&position_y==start_teleport_1_y)||
                   (position_x==end_teleport_1_x&&position_y==end_teleport_1_y))
                {
                    if(start_teleport_1_x==0&&start_teleport_1_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_1_x&&position_y==start_teleport_1_y)
                        {
                            position_x=end_teleport_1_x;
                            position_y=end_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_1_x,object=29,start_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_1_x;
                            position_y=start_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_1_x,object=29,end_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if((position_x==start_teleport_2_x&&position_y==start_teleport_2_y)||
                   (position_x==end_teleport_2_x&&position_y==end_teleport_2_y))
                {
                    if(start_teleport_2_x==0&&start_teleport_2_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_2_x&&position_y==start_teleport_2_y)
                        {
                            position_x=end_teleport_2_x;
                            position_y=end_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_2_x,object=29,start_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_2_x;
                            position_y=start_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_2_x,object=29,end_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if(matrice[position_x][position_y]==3)
                {
                    printf("\nHAI superato il labirinto! wwo\n");
                    flag=1;
                    levels++;
                }
                if(matrice[position_x][position_y]==5)
                {
                    key++;
                    printf("you now have the key for the passage, if you die you'll lose it");
                }
                break;
            case 's':
                position_x+=1;
                if(matrice[position_x][position_y]==-37)
                    {vitae-=1;
                    key=0;
                    printf("\nyou Died. you still have %d(%c)\n",vitae+1,object=3);
                     position_x=x;
                     position_y=y;
                     printf("posizione di partenza: %c\n",matrice[position_x][position_y]);
                     printf("new try, insert new moves: ");
                     scanf("%s",cursore);
                     istruzioni=-1;}
                if(position_x==secret_x&&position_y==secret_y)
                {
                    if(key!=0||(secret_x==0&&secret_y==0))
                    {}
                    else
                    {
                        position_x-=1;
                        printf("\nunfortunatly you don't have the key(%c) to pass through",object=5);
                        printf("\nposizione di partenza: (%c%d,%c%d)",object=18,position_x,object=29,position_y);
                        printf("\nnew try, insert new moves: ");
                        scanf("%s",cursore);
                        istruzioni=-1;
                    }
                }
                if((position_x==start_teleport_1_x&&position_y==start_teleport_1_y)||
                   (position_x==end_teleport_1_x&&position_y==end_teleport_1_y))
                {
                    if(start_teleport_1_x==0&&start_teleport_1_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_1_x&&position_y==start_teleport_1_y)
                        {
                            position_x=end_teleport_1_x;
                            position_y=end_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_1_x,object=29,start_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_1_x;
                            position_y=start_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_1_x,object=29,end_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if((position_x==start_teleport_2_x&&position_y==start_teleport_2_y)||
                   (position_x==end_teleport_2_x&&position_y==end_teleport_2_y))
                {
                    if(start_teleport_2_x==0&&start_teleport_2_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_2_x&&position_y==start_teleport_2_y)
                        {
                            position_x=end_teleport_2_x;
                            position_y=end_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_2_x,object=29,start_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_2_x;
                            position_y=start_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_2_x,object=29,end_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if(matrice[position_x][position_y]==3)
                {
                    printf("\nHAI superato il labirinto. wwo\n");
                    flag=1;
                    levels++;
                }
                if(matrice[position_x][position_y]==5)
                {
                    key++;
                    printf("you now have the key for the passage, if you die you'll lose it");
                }
                break;
            case 'w':
                position_y-=1;
                if(position_y<0)
                {
                    vitae-=1;
                    key=0;
                    printf("\nyou fell into water. you still have %d(%c)\n",vitae+1,object=3);
                     position_x=x;
                     position_y=y;
                     printf("posizione di partenza: %c\n",matrice[position_x][position_y]);
                     printf("new try, insert new moves: ");
                     scanf("%s",cursore);
                     istruzioni=-1;
                }
                if(matrice[position_x][position_y]==-37)
                    {vitae-=1;
                    key=0;
                    printf("\nyou Died. you still have %d(%c)\n",vitae+1,object=3);
                     position_x=x;
                     position_y=y;
                     printf("posizione di partenza: %c\n",matrice[position_x][position_y]);
                     printf("new try, insert new moves: ");
                     scanf("%s",cursore);
                     istruzioni=-1;}
                if(position_x==secret_x&&position_y==secret_y)
                {
                    if(key!=0||(secret_x==0&&secret_y==0))
                    {}
                    else
                    {
                        position_y+=1;
                        printf("\nunfortunatly you don't have the key(%c) to pass through",object=5);
                        printf("\nposizione di partenza: (%c%d,%c%d)",object=18,position_x,object=29,position_y);
                        printf("\nnew try, insert new moves: ");
                        scanf("%s",cursore);
                        istruzioni=-1;
                    }
                }
                if((position_x==start_teleport_1_x&&position_y==start_teleport_1_y)||
                   (position_x==end_teleport_1_x&&position_y==end_teleport_1_y))
                {
                    if(start_teleport_1_x==0&&start_teleport_1_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_1_x&&position_y==start_teleport_1_y)
                        {
                            position_x=end_teleport_1_x;
                            position_y=end_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_1_x,object=29,start_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_1_x;
                            position_y=start_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_1_x,object=29,end_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if((position_x==start_teleport_2_x&&position_y==start_teleport_2_y)||
                   (position_x==end_teleport_2_x&&position_y==end_teleport_2_y))
                {
                    if(start_teleport_2_x==0&&start_teleport_2_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_2_x&&position_y==start_teleport_2_y)
                        {
                            position_x=end_teleport_2_x;
                            position_y=end_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_2_x,object=29,start_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_2_x;
                            position_y=start_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_2_x,object=29,end_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if(matrice[position_x][position_y]==3)
                {
                    printf("\nHAI superato il labirinto. wwo\n");
                    flag=1;
                    levels++;
                }
                if(matrice[position_x][position_y]==5)
                {
                    key++;
                    printf("you now have the key for the passage, if you die you'll lose it");
                }
                break;
            case 'e':
                position_y+=1;
                if(matrice[position_x][position_y]==-37)
                    {vitae-=1;
                    key=0;
                    printf("\nyou Died. you still have %d(%c)\n",vitae+1,object=3);
                     position_x=x;
                     position_y=y;
                     printf("posizione di partenza: %c\n",matrice[position_x][position_y]);
                     printf("new try, insert new moves: ");
                     scanf("%s",cursore);
                     istruzioni=-1;}
                if(position_x==secret_x&&position_y==secret_y)
                {
                    if(key!=0||(secret_x==0&&secret_y==0))
                    {}
                    else
                    {
                        position_y-=1;
                        printf("\nunfortunatly you don't have the key(%c) to pass through",object=5);
                        printf("\nposizione di partenza: (%c%d,%c%d)",object=18,position_x,object=29,position_y);
                        printf("\nnew try, insert new moves: ");
                        scanf("%s",cursore);
                        istruzioni=-1;
                    }
                }
                if((position_x==start_teleport_1_x&&position_y==start_teleport_1_y)||
                   (position_x==end_teleport_1_x&&position_y==end_teleport_1_y))
                {
                    if(start_teleport_1_x==0&&start_teleport_1_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_1_x&&position_y==start_teleport_1_y)
                        {
                            position_x=end_teleport_1_x;
                            position_y=end_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_1_x,object=29,start_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_1_x;
                            position_y=start_teleport_1_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_1_x,object=29,end_teleport_1_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if((position_x==start_teleport_2_x&&position_y==start_teleport_2_y)||
                   (position_x==end_teleport_2_x&&position_y==end_teleport_2_y))
                {
                    if(start_teleport_2_x==0&&start_teleport_2_y==0)
                    {}
                    else
                    {
                        if(position_x==start_teleport_2_x&&position_y==start_teleport_2_y)
                        {
                            position_x=end_teleport_2_x;
                            position_y=end_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,start_teleport_2_x,object=29,start_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }else
                        {
                            position_x=start_teleport_2_x;
                            position_y=start_teleport_2_y;
                            printf("\ndone teleport position from (%c%d,%c%d) to (%c%d,%c%d)",object=18,end_teleport_2_x,object=29,end_teleport_2_y,
                                                                                            object=18,position_x,object=29,position_y);
                        }
                    }
                }
                if(matrice[position_x][position_y]==3)
                {
                    printf("\nHAI superato il labirinto. wwo\n");
                    flag=1;
                    levels++;
                }
                if(matrice[position_x][position_y]==5)
                {
                    key++;
                    printf("you now have the key for the passage, if you die you'll lose it");
                }
                break;
            default:
                break;
            }
        istruzioni++;
        if(cursore[istruzioni]=='\0'&&flag==0)
        {
            printf("\nposizione di partenza: (%c%d,%c%d)",object=18,position_x,object=29,position_y);
            printf("\nyou didn't reach the heart \nplease insert new moves: ");
            scanf("%s",cursore);
            istruzioni=0;
        }
    }
    if(vitae==0)
    {
        printf("\n\nyou died too many times\n\nDo you wanna do a new try?\n\t\t0-yes\t\t1-no\n\t\t");
        scanf("%d",&morte);
        if(morte==0)
            efforts(gender);
    }
    return levels;
}
