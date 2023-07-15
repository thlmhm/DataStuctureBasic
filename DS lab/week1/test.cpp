#include<stdio.h>



#include<conio.h>

#include<string.h>

struct tailieu

{char ma[10];

char ten[30];

int sotrang,namxb;

tailieu *next;

};

tailieu *nhap();

void xoa(tailieu *);

void main()

{tailieu *p,*q,*head;

int i;

clrscr();

head=nhap();;

printf("\nGo Enter Tiep tuc ...");getch();

clrscr();

printf("\nDanh sach tai lieu :\n\n");

printf("%-4s%-10s%-30s%-10s%-10s\n","Stt","Ma","Ten tai lieu","So tr","Nam XB");

p=head;i=0;

while (p!=NULL)

{printf("%-4d%-10s%-30s%-10d%-10d\n",++i,p->ma,p->ten,p->sotrang,p->namxb);

        p=p->next;

}

printf("\nGo Enter Tiep tuc ...");getch();

clrscr();

printf("\nDanh sach tai lieu xuat ban tu nam 1998 :\n\n");

printf("%-4s%-10s%-30s%-10s%-10s\n","Stt","Ma","Ten tai lieu","So tr","Nam XB");

p=head;i=0;

while (p!=NULL)

{if(p->namxb>=1998)printf("%-4d%-10s%-30s%-10d%-10d\n",
                         ++i,p->ma,p->ten,p->sotrang,p->namxb);

    p=p->next;

}

}

void xoa(tailieu *p)

{tailieu *q;

while (p!=NULL)

{q=p; p=p->next; delete q;

}

}

tailieu *nhap()

{tailieu *p,*q,*h;

char s[10];

h=NULL;

printf("Nhap du lieu cua cac tai lieu, ket thuc go Enter :\n");

printf("Tai lieu thu 1 :\n");

printf("Ma so : ");gets(s);

if (strcmp(s,""))

{p=new tailieu;

strcpy(p->ma,s);

printf("Ten tai lieu : ");gets(p->ten);

printf("So trang : ");cin>>p->sotrang;

printf("Nam xuat ban : ");cin>>p->namxb;

p->next=NULL;

h=p;q=p;

printf("Tai lieu tiep theo :\n");

printf("Ma so : ");gets(s);

while (strcmp(s,""))

{p=new tailieu;

       strcpy(p->ma,s);

       printf("Ten tai lieu : ");gets(p->ten);

       printf("So trang : ");cin>>p->sotrang;

       printf("Nam xuat ban : ");cin>>p->namxb;

       p->next=NULL;

       q->next=p;

       q=p;

       printf("Tai lieu tiep theo :\n");

       printf("Ma so : ");gets(s);

}

}

return h;

}
