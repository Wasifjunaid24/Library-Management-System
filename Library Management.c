#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct date{
	int d;
	int m;
	int y;
};
struct book{
	int bookid;
	char bookname[30];
	char authorname[30];
	char studentname[30];
	char category[30];
	struct date issuedate;
}bookinfo;
headMessage(const char* title){
    system("cls");
      printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############            Library management System              ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t%s",title);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
start(){
    headMessage("PF PROJECT");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  ********************************************************\n");
    printf("\n\t\t\t        =============================================");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =============================================");
    printf("\n\n\t\t\t  ********************************************************\n");
    printf("\n\n\n\t\t\t Press Enter to continue.....");
    getch();
}

add()
{
    FILE *fp;
	fp = fopen("lms.bin","ab+");
	if(fp == NULL){
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }		
	headMessage("ADD BOOKS");
	printf("\n\n\t\t\tENTER BOOK DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    
    printf("\n\t\t\tBook ID NO: ");
    scanf("%d",&bookinfo.bookid);
    fflush(stdin);   
	    
    printf("\n\t\t\tBook Name: ");
    gets(bookinfo.bookname);
	fflush(stdin);    	
	    
	printf("\n\t\t\tAuthor Name: ");
	gets(bookinfo.authorname);
	fflush(stdin);       
	 
	printf("\n\t\t\tStudent Name: ");
	gets(bookinfo.studentname);
	fflush(stdin);	
	
	printf("\n\t\t\tCategory Name: ");
	gets(bookinfo.category);
	fflush(stdin);
	 
	printf("\n\t\t\tEnter date(dd): ");
	scanf("%d",&bookinfo.issuedate.d);
	fflush(stdin);   
    
	printf("\n\t\t\tEnter month(mm): ");
	scanf("%d",&bookinfo.issuedate.m);
	fflush(stdin);
        
	printf("\n\t\t\tEnter year(yyyy): ");
	scanf("%d",&bookinfo.issuedate.y);
	fflush(stdin);
    
	fwrite(&bookinfo, sizeof(bookinfo), 1, fp);	     
    fclose(fp); 	
}

search()
{
    int found=1;
    char searchbook[30];
    FILE *fp;
	fp = fopen("lms.bin","rb");
    if(fp == NULL){
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH BOOKS");
    
    fflush(stdin);
    printf("\n\n\t\t\tEnter Book Name to search: ");    
    gets(searchbook);
    rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
		if(strcmp(bookinfo.bookname, searchbook)==0)
        {
            printf("\n\t\t\tBook ID = %d\n",bookinfo.bookid);
        	printf("\t\t\tBook Name = %s\n",bookinfo.bookname);
        	printf("\t\t\tAuthor Name = %s\n",bookinfo.authorname);
        	printf("\t\t\tStudent Name = %s\n",bookinfo.studentname);
        	printf("\t\t\tCategory = %s\n",bookinfo.category);
        	printf("\t\t\tIssue date(day/month/year) =  %d/%d/%d\n",bookinfo.issuedate.d,
        	bookinfo.issuedate.m, bookinfo.issuedate.y);
        	found = 0;
            break;
        }
    }
    if(found==1){
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress Enter to go to main menu.....");
    getchar();	
}

view()
{
	int found = 0;
	int count = 1;
	headMessage("BOOKS DETAILS");
	FILE *fp = fopen("lms.bin","rb");
	if(fp == NULL){
     	printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
	rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
        printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ID = %d\n",bookinfo.bookid);
        printf("\t\t\tBook Name = %s\n",bookinfo.bookname);
        printf("\t\t\tAuthor Name = %s\n",bookinfo.authorname);
        printf("\t\t\tStudent Name = %s\n",bookinfo.studentname);
        printf("\t\t\tCategory = %s\n",bookinfo.category);
        printf("\t\t\tIssue date(day/month/year) =  (%d/%d/%d)\n\n",bookinfo.issuedate.d,
        		bookinfo.issuedate.m, bookinfo.issuedate.y);
        found = 1;
        count++;
    }
    fclose(fp);
    if(found==0)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();	
}

category(){
	int found = 0;
	int count = 1;
	char cat[30];
	headMessage("BOOKS DETAILS BY CATEGORY");
	FILE *fp = fopen("lms.bin","rb");
	if(fp == NULL){
     	printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    fflush(stdin);
    printf("\n\n\t\t\tEnter category to search: ");    
    gets(cat);
	rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
    	if(strcmp(bookinfo.category, cat)==0)
        {
        printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ID = %d\n",bookinfo.bookid);
        printf("\t\t\tBook Name = %s\n",bookinfo.bookname);
        printf("\t\t\tAuthor Name = %s\n",bookinfo.authorname);
        printf("\t\t\tStudent Name = %s\n",bookinfo.studentname);
        printf("\t\t\tCategory = %s\n",bookinfo.category);
        printf("\t\t\tIssue date(day/month/year) =  (%d/%d/%d)\n\n",bookinfo.issuedate.d,
        		bookinfo.issuedate.m, bookinfo.issuedate.y);
        found = 1;
        count++;
    	}
    }
    fclose(fp);
    if(found==0)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
removebook()
{
    int found = 0;
    int deleteid = 0;
    char bookName[30] = {0};
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    int status = 0;
    headMessage("Delete Books Details");
    fp = fopen("lms.bin","rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fp1 = fopen("recycle.bin","wb");
    if(fp1 == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    scanf("%d",&deleteid);
    fflush(stdin);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp))
    {
        if(bookinfo.bookid==deleteid)					
        {
            found = 1;
        }
        else
        {
        	fwrite(&bookinfo,sizeof(bookinfo), 1, fp1);            
        }
    }
    if(found==1)
	{	
        printf("\n\t\t\tRecord deleted successfully.....");
    }
    else
	{
		printf("\n\t\t\tNo Record Found.....");        
    }    
    fclose(fp);
    fclose(fp1);
    remove("lms.bin");
    rename("recycle.bin","lms.bin");
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}

edit(){
    int found=1;
    char editbook[30];
    FILE *fp;
	fp = fopen("lms.bin","rb+");
    if(fp == NULL){
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("EDIT BOOKS");
    
    fflush(stdin);
    printf("\n\n\t\t\tEnter Book Name to edit: ");    
    gets(editbook);
    rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
		if(strcmp(bookinfo.bookname, editbook)==0)
        {
        	printf("\t\t\tPrevious Book ID = %d\n",bookinfo.bookid);
        	printf("\t\t\tPrevious Book Name = %s\n",bookinfo.bookname);
        	printf("\t\t\tPrevious Author Name = %s\n",bookinfo.authorname);
        	printf("\t\t\tPrevious Student Name = %s\n",bookinfo.studentname);
        	printf("\t\t\tPrevious Category = %s\n",bookinfo.category);
        	printf("\t\t\tPrevious Issue date(day/month/year) =  (%d/%d/%d)\n\n",bookinfo.issuedate.d,
        		bookinfo.issuedate.m, bookinfo.issuedate.y);
        		
            printf("\n\t\t\tNew Book ID: ");
            scanf("%d",&bookinfo.bookid);
    		fflush(stdin);
        	printf("\t\t\tNew Book Name: ");
        	gets(bookinfo.bookname);
   			fflush(stdin);
        	printf("\t\t\tNew Author Name: ");
        	gets(bookinfo.authorname);
    		fflush(stdin);
        	printf("\t\t\tNew Student Name: ");
        	gets(bookinfo.studentname);
    		fflush(stdin);
    		printf("\t\t\tNew Category: ");
        	gets(bookinfo.studentname);
    		fflush(stdin);    		
        	printf("\t\t\tNew date(dd): ");
			scanf("%d",&bookinfo.issuedate.d);
			fflush(stdin);       
			printf("\t\t\tNew month(mm): ");
			scanf("%d",&bookinfo.issuedate.m);
			fflush(stdin);
      		printf("\t\t\tNew year(yyyy): ");
			scanf("%d",&bookinfo.issuedate.y);
			fflush(stdin);
			fseek(fp,-sizeof(bookinfo),SEEK_CUR);
			fwrite(&bookinfo,sizeof(bookinfo), 1, fp);
        	found = 0;
            break;
        }
    }
    if(found==1){
        printf("\n\t\t\tNo Such Record");
    }
    else{
    	printf("Record Edited Successfully.....");
	}
    fclose(fp);
    printf("\n\n\n\t\t\tPress Enter to go to main menu.....");
    getchar();	
}

menu(){
    int choice = 0;
    do{
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Book List");
        printf("\n\t\t\t4.View Books By Categories");
        printf("\n\t\t\t5.Edit Book");
        printf("\n\t\t\t6.Delete Book");     
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        case 3:
            view();
            break;
        case 4:
            category();
            break;    
        case 5:
        	edit();
        	break;
        case 6:
            removebook();
            break;        
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");    
        }                                            
    }while(choice!=0);                                        
}
int main()
{    
    start();
    menu();
    
    return 0;
}
