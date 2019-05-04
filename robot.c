#include <stdio.h>
#include <string.h>
#include <windows.h>

struct w
{
    char in[100];
};

char endwords[100]="�ټ�";
char ini[100]="��ʼ��";
char cha[100]="�޸�";
char clean[100]="����";
void initialize();

void initi()//��ȡ��ʼ���ʻ�
{
    FILE *init=NULL;
    init=fopen("init.txt","r");
    fscanf(init,"%s\n%s\n%s\n%s",endwords,ini,cha,clean);
    fclose(init);
}

void learning()//ѧϰģʽ
{
    char learning[100];
    char feedback[100];
    printf("����˵��");
    scanf("%s",&learning);
    printf("��Ӧ��˵��");
    scanf("%s",&feedback);

    FILE *words=NULL;
    words=fopen("words.txt","a");
    while(feof(words)==0)
    {
        fprintf(words,"\n%s\n%s",learning,feedback);
        fclose(words);
        printf("ѧϰ��ϣ�\n\n");
        return ;
    }
}

char understand(char input[])//���ģʽ
{
    char search[100];
    FILE *words=NULL;
    words=fopen("words.txt","r");
    if(words==NULL)
    {
        MessageBox(NULL,"   ��ʼ�ļ���ʧ�������������ļ���   ","���󣡣���",MB_OK);
        exit (0);
    }

    while(feof(words)==0)
    {
        fscanf(words,"%s\n",&search);

        if(strcmp(search,input)==0)
        {
            char feedback[100];
            fscanf(words,"%s",&feedback);
            printf("%s\n",feedback);
            return;
        }
    }

    int a;
    printf("��Ǹ����̫������~�Ҳ�����⡣\n");
    printf("��Ҫ����ѧϰ������(��Ҫ������1)\n");
    scanf("%d",&a);
    if(a==1)
    {
        learning();
    }

    fclose(words);
}

void changeM()//�޸�ģʽ
{
    struct w a[1000];//�ʿ��С�ɱ�
    struct w search;
    struct w change;

    FILE *words=NULL;
    words=fopen("words.txt","r");
    if(words==NULL)
    {
        MessageBox(NULL,"   ��ʼ�ļ���ʧ�������������ļ���   ","���󣡣���",MB_OK);
        exit (0);
    }

    int i=0,t=0;
    while(feof(words)==0)
    {
        fscanf(words,"%s\n",&a[i].in);
        i++;
        t=i;
    }

 a3:printf("��Ҫ�޸�ʲô���䣿\n");
    getchar();
    gets(search.in);

    i=0;
    int flag=0;
    while(i<=t)
    {
        if(strcmp(search.in,a[i].in)==0)
        {
            printf("ԭ���䣺%s\n",a[i+1].in);
            printf("�޸ĺ���䣺");
            gets(change.in);
            strcpy(a[i+1].in,change.in);
            printf("�޸ĳɹ���\n");
            flag=1;
            break;
        }
        i++;
    }

    if(flag==0)
    {
        int n;
        printf("���䲻���ڣ����������롣(����Ҫ�޸�������1�ص�������棬��Ҫ�޸�������2)\n");
        scanf("%d",&n);
        if(n == 1)
        {
           fclose(words);
           return;
        }
        else
        {
            goto a3;
        }
    }

    words=fopen("words.txt","w");
    i=0;
    while(i<=t)
    {
        fprintf(words,"%s\n",a[i].in);
        i++;
    }
    fclose(words);

}

void check(char input[])
{
    char search[100];
    FILE *words=NULL;
    words=fopen("words.txt","r");
    if(words==NULL)
    {
        MessageBox(NULL,"   ��ʼ�ļ���ʧ�������������ļ���   ","���󣡣���",MB_OK);
        exit (0);
    }

    while(feof(words)==0)
    {
        fscanf(words,"%s\n",&search);

        if(strcmp(search,input)==0)
        {
            printf("�����дʻ��ͻ���������룺");
            initialize();
        }
    }
}


void initialize()//��ʼ���趨
{
    FILE *save;
    save=fopen("save.txt","w");
    int a=1;
    fprintf(save,"%d\n",a);
    fclose(save);

    int b;
 a1:printf("�Ƿ�����ʼ���趨��(��Ҫ������1������Ҫ������2�������ٴν����ʼ���趨�����롰��ʼ����)\n");
    scanf("%d",&b);
    getchar();

    switch(b)
    {
        case 1:
               {
                printf("��������ʲôʱ��������������˽��̣�����ʼ�趨Ϊ���ټ���\n�趨��");
                scanf("%s",&endwords);
                check(endwords);

                printf("��������ʲôʱ�����ʼ�����̣�����ʼ�趨Ϊ����ʼ����\n�趨��");
                scanf("%s",&ini);
                check(ini);

                printf("��������ʲôʱ�����޸Ľ��̣�����ʼ�趨Ϊ���޸ģ�\n�趨��");
                scanf("%s",&cha);
                check(cha);

                printf("��������ʲôʱ����������ʼ�趨Ϊ��������\n�趨��");
                scanf("%s",&clean);
                check(clean);

                FILE *init=NULL;
                init=fopen("init.txt","w");
                fprintf(init,"%s\n%s\n%s\n%s",endwords,ini,cha,clean);
                fclose(init);

                printf("�趨��ϣ�\n");
                return;
               }
        case 2:return;
        default:goto a1;break;
    }
    return;
}

void main()
{
    char input[100];

    //�ж��Ƿ��һ�δ�
    int s;
    FILE *save=NULL;
    save=fopen("save.txt","r");
    if(save==NULL)
    {
        printf("�޷��ҵ���");
        return;
    }

    fscanf(save,"%d",&s);
    if(s==0)
    {
       initialize();
    }
    fclose(save);


    printf("���ã��������Ķ������ѣ�������ʲô��Ҫ��\n\n");
    initi();

    while(1)
    {
     a2:printf("��˵��");
        scanf("%s",&input);

        if(strcmp(input,endwords)==0)
        {
            printf("��������ʮ�ֿ���~\n");
            break;
        }
        if(strcmp(input,ini)==0)
        {
            initialize();
            goto a2;
        }
        if(strcmp(input,cha)==0)
        {
            changeM();
            goto a2;
        }
        if(strcmp(input,clean)==0)
        {
            system("cls");
            goto a2;
        }
        understand(input);
    }
}
