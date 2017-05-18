
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20


int cancel=NULL;
int users;
typedef struct DANE
{

	int ilosc_ocen;
	int user_id;
	int weight[MAX];
	float ocena[MAX];//
	int grade_id[MAX];
	
}Dane;
Dane dane1[512];
typedef struct STUDENT Student;
struct STUDENT
{
	Dane dane;
	Student *next;
	
};

Student *stworz_element()
{
	Student *element;
	int user_id;

	printf("ID:");
	scanf("%d",&user_id);
	

	
int i,j;
int licznik=1;
	system("cls");


	element=malloc(sizeof(Student));
	element->next=NULL;
	element->dane.user_id=user_id;

printf("Ile ocen chcesz wpisac?\n");
scanf("%d",&j);
	float ocena[j];//
	int weight [j];
    int grade_id[j];
	printf("Wpisywanie Ocen i wag.\n");
	for(i=0;i<j;i++)
	{    
	    
	 
	    printf("Ocena:");
	    scanf("%f",&ocena[i]);
		if(ocena[i]<0||ocena[i]>6)
		{
			printf("Nieprawid³owa ocena!\nWpisz ponownie:");
			
			scanf("%f",&ocena[i]);
			
		}
	
		
           	
		printf("Waga:");
		scanf("%d",&weight[i]);
	    grade_id[i]=user_id+licznik;
	    
		 element->dane.ocena[i]=ocena[i];
	     element->dane.weight[i]=weight[i];
		 element->dane.grade_id[i]=grade_id[i];
		 licznik++;
             
	}
	element->dane.ilosc_ocen=j;

	
   
    return element;
}
void dodaj(Student **head)
{
	Student *tmp=stworz_element();
	
	if(*head!=NULL)
	{
		tmp->next=*head;
		
	}
	*head=tmp;

}

void zapisz_do_pliku(Student *head)

{
	int i;
	
	FILE *zapisz ;
	Student *tmp;
	if (head == NULL)
		printf("Nie ma elementow do zapisania");
		
		else
	{
		if((zapisz = fopen("grades.txt", "a"))==NULL)
		{
			printf("blad\n");
			
		}
		else{
		
		    tmp = head;
			while (tmp != NULL)
			{
				fprintf(zapisz, "\n%d ", tmp->dane.user_id);
				fprintf(zapisz, "\n%d ", tmp->dane.ilosc_ocen);
				
				for(i=0;i<tmp->dane.ilosc_ocen;i++)
				{
					fprintf(zapisz, "\n%.2f ", tmp->dane.ocena[i]);
			
					
					
				}
					for(i=0;i<tmp->dane.ilosc_ocen;i++)
				{
					fprintf(zapisz, "\n%d ", tmp->dane.weight[i]);
			
					
					
				}
					for(i=0;i<tmp->dane.ilosc_ocen;i++)
				{
					fprintf(zapisz, "\n%d ", tmp->dane.grade_id[i]);
			
				}
					
				tmp=tmp->next;
				
				
			}
			printf("zapisano\n");
       	}
		
	}
	fclose (zapisz);
}

void odczyt()
{
		
	int i,j,k,l;


	FILE *fp;
	if((fp=fopen("grades.txt","r"))==NULL)
	{
		printf("NIE MOZNA ODCZYTAC");
	}

for(i=0;i<users;i++)
{
    fscanf(fp,  "%d",&dane1[i].user_id);
	fscanf(fp,  "%d",&dane1[i].ilosc_ocen);
	for(j=0;j<dane1[i].ilosc_ocen;j++)
{

	fscanf(fp,"%f",&dane1[i].ocena[j]);
}
   
for(k=0;k<dane1[i].ilosc_ocen;k++)
{
		fscanf(fp,"%d",&dane1[i].weight[k]);
}

for(l=0;l<dane1[i].ilosc_ocen;l++)
{
		fscanf(fp,"%d",&dane1[i].grade_id[l]);
}
}
	fclose(fp);
}

void edit_grade(int grade_id1)
{   
int t=0;
float new_grade;
int new_weight;
	int amount;
	int i,j;
	for(i=0;i<2;i++)
	{    amount=dane1[i].ilosc_ocen;
		for(j=0;j<amount;j++)
		{
			if(dane1[i].grade_id[j]==grade_id1)
			{
				printf("Znaleziono\n");
				printf("Wpisz ocene:");
				scanf("%f",&new_grade);
				dane1[i].ocena[j]=new_grade;
				printf("Wpisz wage:");
				scanf("%d",&new_grade);
				dane1[i].weight[j]=new_grade;
				t=1;
				
			}
		
			
		
			
		}
	}
	
	if(t==0)
	{
		printf("Nie znaleziono.");
	}
}
void save()
{	
int i,j,k,l;
FILE *fp;
	if((fp=fopen("grades.txt","w"))==NULL)
	{
		printf("NIE MOZNA ODCZYTAC");
	}
	
for(i=0;i<users;i++)
{
	
    fprintf(fp,  "\n%d",dane1[i].user_id);
	fprintf(fp,  "\n%d",dane1[i].ilosc_ocen);
	
	for(j=0;j<dane1[i].ilosc_ocen;j++)
{
if(dane1[i].ocena[j]!=cancel)
	fprintf(fp,"\n%.2f",dane1[i].ocena[j]);
	if(dane1[i].ocena[j]==cancel)
	dane1[i].ilosc_ocen++;
	
}
   
for(k=0;k<dane1[i].ilosc_ocen;k++)
{
	if(dane1[i].weight[k]!=cancel)
		fprintf(fp,"\n%d",dane1[i].weight[k]);
}

for(l=0;l<dane1[i].ilosc_ocen;l++)
{
	if(dane1[i].grade_id[l]!=cancel)
		fprintf(fp,"\n%d",dane1[i].grade_id[l]);
}
}
fclose(fp);
}
void remove_grade(int grade_id2)
{
	
	int users_id;
	
    int amount;
	int i,j;  
	int t=0;
	
	for(i=0;i<users;i++)
     {  
	
		
	    amount=dane1[i].ilosc_ocen;
	    
		   for(j=0;j<amount;j++)
		   {
		   if(dane1[i].grade_id[j]==grade_id2)
		     	{
		     		
			
			
			
				dane1[i].ocena[j]=cancel;
			
				dane1[i].weight[j]=cancel;
				dane1[i].grade_id[j]=cancel;
				dane1[i].ilosc_ocen=	dane1[i].ilosc_ocen-1;
				printf("Ilosc ocen wynosi:%d",	dane1[i].ilosc_ocen);
				t=1;
				
	          	}
		
			
		}
     	}
if(t==0)
{
	printf("Nie znaleziono ID.\n");
}	
}


void odczyt_uzytkownikow()
{
	int amount;
	FILE *st;
	if((st=fopen("users.txt","r"))==NULL)
	        	{
			printf("nie mozna otworzyc");
				}
	else
	{
		fscanf(st,"%d",&users);
	

	}
	fclose(st);
}
void zapis_uzytkownikow()
{
	
	
	int amount;
	FILE *st;
	if((st=fopen("users.txt","w"))==NULL)
	        	{
			printf("nie mozna otworzyc");
				}
	else
	{
		fprintf(st,"%d",users);
	
		
	}
	fclose(st);
	
	
	
	
	
}
int main(int argc, char *argv[]) {

	int wybor;
	int n;
	
	Student *head;
	do 
	{    
	    
		printf("1.Dodaj ocene\n");
		printf("2.Edytuj ocene\n");
		printf("3.Usun ocene\n");
		printf("4.Zapisz i wyjdz\n");
		
		scanf("%d",&wybor);
		switch(wybor)
		{
			case 1:
				odczyt_uzytkownikow();
				dodaj(&head);
				users++;
			   
			    zapis_uzytkownikow();
			    
				break;
			case 2:
					odczyt_uzytkownikow();
				    odczyt();
				
			     	edit_grade(10);
				    save();
					 
			
				
				break;
			
				case 3:
					   odczyt_uzytkownikow();
						odczyt();
						remove_grade(33334);
						save();
						break;
					
					
			
					
					break;
				case 4:
				
					 	zapisz_do_pliku(head);
					  
					
					
						
					
			default:
				
					printf("KONIEC\n");
				
		}
		
	}while(wybor!=4);


	   
	
	     
	return 0;
}
