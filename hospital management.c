#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define rw 80
#define cl 50
#include<windows.h> //  header file for gotoxy

COORD coord={0,0}; // this is global variable
                                   //center of axis is set to the top left cornor of the screen

void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
FILE*fp,*fp1,*f1,*f2;
int s,z;
char fn1[]="opd12.patient";
char fn2[]="oopd12.patient";
struct hospital{
		char name[20],address[20],ch;
		int age,roomno,sn;
		char disease[30],department[20],date[15];
		char recommendation[50],category[30];
		char test[15][20];
		float testfee[15];
		float totalfee;
		float balance;
		}p,q;
char string[20];
typedef struct hospital STES;
void newrecord(int l);
void print();
void displaytest();
void mainscreen();
void newrecord1();
void displaydepartment();
void edit1();
void editrecord();
void switch1();
void main()
{
	int a,i,n,y;
	char c,d;
	char date1[15],date2[15],string1[20];
	unsigned int tsz;

	system("cls");
	mainscreen();
	label3:
	gotoxy(20,15);
	printf("Enter today's Date(yyyy/mm/dd)");
	fflush(stdin);gotoxy(28,19);
	scanf("%[^\n]",date2);
	if((date2[8]>'3')||(date2[7]!='/')||(date2[5]>'3')||(date2[4]!='/'))
	{
		system("cls");
		mainscreen();
		gotoxy(23,13);
		printf("Wrong Entry");
		goto label3;
	}
	system("cls");
	mainscreen();
	label1:


	gotoxy(22,15);(14);
	printf("Enter the corresponding no");gotoxy(22,19);
	printf("1.Add new patient record");gotoxy(22,21);
	printf("2.Search  or edit record");gotoxy(22,23);
	printf("3.Know the records of patients");gotoxy(22,25);
	printf("4.Discharge the patient");gotoxy(22,27);
	printf("5.Exit from the program");gotoxy(25,30);
	fflush(stdin);
	scanf("%c",&d);
	switch(d)
	{
		case '1':
		      {

			{   fp=fopen(fn1,"rb");
				if(fp==NULL)
				s=1;
				else
				{
				while(fread(&p,sizeof(STES),1,fp))
				p.sn=s+1;
				}
				fclose(fp);
			}
			system("cls");
			mainscreen();
			label:
			gotoxy(22,19);
			printf("Enter `o' for O.P.D. & `e'for Emergency");
			gotoxy(35,21);
			fflush(stdin);
			scanf("%c",&c);
			if(c=='o')
			{
				system("cls");
				mainscreen();
				gotoxy(23,11);
				printf("ADDING NEW O.P.D.PATIENT RECORD");
				gotoxy(21,12);
				printf("~~~~~~~~~~~~~");
				s=1;
				newrecord(s);
				newrecord1(s);

				if((fp=fopen(fn1,"ab+"))==NULL)
				{
					printf("Cannot open the file f1");
					getch();
					exit(1);
				}
				for(a=0;a<15;a++)
				p.testfee[a]=0;
				strcpy(&p.test[1][0],"0");
				p.totalfee=0;p.balance=0;
				strcpy(&p.test[0][0],"O.P.D. charge");
				p.testfee[0]=200;

				p.totalfee=200;
				strcpy(p.category,"O.P.D.Patient");
				p.balance=200;
				strcpy(p.recommendation,"Admitted to O.P.D.");
				strcpy(p.date,date2);
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);
				s=s+1;
				if((fp=fopen(fn1,"ab+"))==NULL)
				{
						printf("Cannot open the file f1");
						getch();
						exit(1);
				}
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);


			}
			else if(c=='e')
			       {
				 system("cls");
				 mainscreen();

				 gotoxy(23,11);
				 printf("ADDING NEW EMERGENCY PATIENT RECORD");

				 gotoxy(23,12);
				 printf("~~~~~~~~~~~~");
				 newrecord(s);
				 newrecord1(s);
				 if((fp=fopen(fn2,"ab+"))==NULL)
					{
						printf("Cannot open the file f1");
						getch();
						exit(1);
					}
					for(a=0;a<15;a++)
					p.testfee[a]=0;
					strcpy(&p.test[1][0],"0");
					p.totalfee=0;p.balance=0;

			       p.totalfee=250;
			       strcpy(p.date,date2);
			       strcpy(&p.test[0][0],"Emergency Charge");
			       strcpy(p.category,"Emergency Patient");
			       strcpy(p.recommendation,"Admitted to Emergency");
			       p.testfee[0]=250;
			       p.balance=250;
			       fwrite(&p,sizeof(p),1,fp);
			       fclose(fp);
			      if((fp=fopen(fn2,"ab+"))==NULL)
				{
						printf("Cannot open the file f1");
						getch();
						exit(1);
				}
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);

			       }
			else
			{
				system("cls");
				mainscreen();
				gotoxy(22,15);
				printf("Wrong choice");

				goto label;
			}
			break;
		      }
		case '2':
		      {
		       system("cls");
		       mainscreen();
		       editrecord();
		       break;
		      }
		case '5':
		      {
			system("cls");
			mainscreen();
			(14); gotoxy(30,24);
			printf("THANK U");gotoxy(30,26);
		       //	cprintf("SAVING UR SETTINGS"); gotoxy(30,28);
			printf("BYE...........");
			getch();
			exit(1);
			break;
			}
		case '4':
			{
				if((fp=fopen(fn1,"rb"))==NULL)
				{
					printf("cannot open the file");
					getch();
					exit(1);
				}

				if((f1=fopen("delete","wb"))==NULL)
				{
					printf("cannot open the file");
					getch();
					exit(1);
				}

				int i,k;
	gotoxy(10,41);
	printf("Details:");gotoxy(18,41);
	printf(" %s",p.recommendation);gotoxy(10,45);(4);
	printf("Press");(15+128);
	printf(" `Enter'");(4);
	printf(" for financial records");
	getch();
	system("cls");
	mainscreen();
	(14);     gotoxy(20,8);
	printf("The list of expenditure of patient no:");
	printf("%d",p.sn);
	for(z=0,i=0,k=11;p.testfee[z]!=0;i++,z++)
	{
		gotoxy(20,k);
		printf("%d)",i+1);
		printf(" %s",&p.test[z][0]);gotoxy(40,k);
		printf("Rs.%0.2f",p.testfee[z]);
		k=k+2;
	}
	gotoxy(20,k+2);
	printf("Total charge=");
	printf("Rs.%0.2f",p.totalfee);
	gotoxy(20,k+4);
	printf("Total Deposited:");
	printf("Rs.%0.2f",p.balance);
	if(p.totalfee>p.balance)
	{
		 gotoxy(20,k+6);
		printf("Total money to pay=");

		printf("%0.2f",p.totalfee-p.balance);
	}
	else
	{
		 gotoxy(20,k+6);
		printf("Total money to return=");

		printf("%0.2f",p.balance-p.totalfee);
		getch();
		printf("/n Amount Successfully Paid");
	}

}


		case '3':
			{       label6:
				system("cls");
				mainscreen();
				gotoxy(22,15);
				printf("Enter the corresponding no");gotoxy(22,19);
				printf("1.Records of patients in alphabatecal order");gotoxy(22,21);
				printf("2.Records of Emergency patients");gotoxy(22,23);
				printf("3.Records of O.P.D. patients");gotoxy(22,25);
				printf("4.Records in paricular date");gotoxy(22,27);
				printf("5.Return to main menu");gotoxy(25,30);
				fflush(stdin);
				scanf("%c",&d);
				switch(d)
				{
				case '1':
					{
					 if((fp=fopen(fn2,"rb+"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
					 fseek(fp,0,SEEK_END);
					 tsz=ftell(fp);
					 n=(int)(tsz/sizeof(STES));
					 for(i=0;i<(n-1);i++)
					 {
						for(a=i+1;a<n;a++)
						{
						fseek(fp,i*sizeof(STES),SEEK_SET);
						fread(&p,sizeof(STES),1,fp);
						fseek(fp,a*sizeof(STES),SEEK_SET);
						fread(&q,sizeof(STES),1,fp);
						if(strcmp(p.name,q.name)>1)
							{
							fseek(fp,i*sizeof(STES),SEEK_SET);
							fwrite(&q,sizeof(STES),1,fp);
							fseek(fp,a*sizeof(STES),SEEK_SET); fflush(stdin);
							fwrite(&p,sizeof(STES),1,fp);
							}
						}
					}
					rewind(fp);
					system("cls");
					mainscreen();
					gotoxy(3,20);
					printf("Ready to Display the patient records according to alphabatecal order of names");
					gotoxy(27,25);
					printf("Press");(15+128);
					printf(" `Enter' ");
					printf("to continue");
					getch();
					while(fread(&p,sizeof(STES),1,fp))
					{
					system("cls");
					mainscreen();
					print();
					gotoxy(17,10);
					printf("DISPLAYING-RECORD-ACCORDING-TO-PATIENTS-NAMES");
					gotoxy(16,11);
					printf("---------------------------------------------");
					edit1();


					gotoxy(20,46);
					printf("Press");(15+128);
					printf(" `Enter'");
					printf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;

					}
					gotoxy(60,46);
					getch();

				}
				system("cls");
				mainscreen();
				gotoxy(30,25);
				printf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}
			case '5':
				{
				system("cls");
				mainscreen();
				 goto label1;
				 }
			case '2':
				{
				system("cls");
				mainscreen();
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
				gotoxy(15,20);

				printf("Ready to Display records of Emergency Patients");
				gotoxy(27,25);
				printf("Press");(15+128);
				printf(" `Enter' ");
				printf("to continue");
				getch();
				while(fread(&p,sizeof(STES),1,fp))
				{
					if(strcmp(p.category,"Emergency Patient")==NULL)
					{
					system("cls");
					mainscreen();
					print();
					gotoxy(17,10);
					printf("::DISPLAYING-RECORDS-OF-EMERGENCY-PATIENTS::");
					gotoxy(16,11);
					printf("---------------------------------------------");
					edit1();


					gotoxy(20,45);
					printf("Press");
					printf(" `Enter'");
					printf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					gotoxy(60,46);
					getch();
					}
				}
				system("cls");
				mainscreen();
				gotoxy(30,25);
				printf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}
			case '3':
				{
				system("cls");
				mainscreen();
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
				gotoxy(15,20);

				printf("Ready to Display records of O.P.D Patients");
				gotoxy(27,25);
				printf("Press");
				printf(" `Enter' ");
				printf("to continue");
				getch();
				while(fread(&p,sizeof(STES),1,fp))
				{
					if(strcmp(p.category,"O.P.D.Patient")==NULL)
					{
					system("cls");
					mainscreen();
					print();
					gotoxy(17,10);
					printf("::DISPLAYING-RECORDS-OF-OPD-PATIENTS::");
					gotoxy(16,11);
					printf("---------------------------------------------");
					edit1();
					gotoxy(20,46);
					printf("Press");
					printf(" `Enter'");
					printf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					gotoxy(60,46);
					getch();
					}
				}
				system("cls");
				mainscreen();
				gotoxy(30,25);
				printf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}
		case '4':
				{
				system("cls");
				mainscreen();
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
				label8:
				gotoxy(27,20);

				printf("Enter the `Date' of a paricular day(yyyy/mm/dd)");
				gotoxy(35,25);fflush(stdin);
				scanf("%s",string);
				if((string[8]>'3')||(string[7]!='/')||(string[5]>'3')||(string[4]!='/'))
				{
				system("cls");
				mainscreen();
				gotoxy(23,13);
				printf("Wrong Entry");
				goto label8;
				}
			       //	getch();
				while(fread(&p,sizeof(STES),1,fp))
				{
					if(strcmp(string,p.date)==NULL)
					{
					system("cls");
					mainscreen();
					print();
					gotoxy(17,10);
					printf("::DISPLAYING-RECORDS-OF-");
					printf("DATE >%s",p.date);
					gotoxy(16,11);
					printf("---------------------------------------------");
					edit1();


					gotoxy(20,46);
					printf("Press");
					printf(" `Enter'");
					printf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					gotoxy(60,46);
					getch();
					}
				}
				system("cls");
				mainscreen();
				gotoxy(30,50);
				printf("::No Further Records::");   gotoxy(40,30);
				getch();
				fclose(fp);
				break;
				}

			default:
				{
				system("cls");
				mainscreen();
				gotoxy(22,11);
				printf("Wrong choice");gotoxy(22,13);
				 printf("Retype choice");
				goto label6;
				}
			}
		}break;





		default:
		       {
			system("cls");
			mainscreen();
		    gotoxy(22,11);
			printf("Wrong choice");gotoxy(22,13);
			 printf("Retype choice");
			goto label1;
			}

	}
	system("cls");
	mainscreen();
	goto label1;
}
void newrecord(int l)
{
	char q;
	p.sn=l;
	displaydepartment();
	gotoxy(5,14);
	printf("Record of patient no:");
	printf(" %d",s);
	gotoxy(5,17);
	printf("Name:");

	gotoxy(5,20);
	printf("Address:");

	gotoxy(5,23);
	printf("Age: ");

	gotoxy(5,26);
	printf("Sex(m/f): ");

	gotoxy(5,29);
	printf("Disease Descrp:");
	gotoxy(9,30);
	printf("(In Short)");

	gotoxy(5,33);
	printf("Reff. Specialist no:");
	fflush(stdin);gotoxy(10,17);
	scanf("%[^\n]",p.name);
	p.name[0]=toupper(p.name[0]);
	gotoxy(14,20);
	fflush(stdin);
	scanf("%[^\n]",p.address);
	gotoxy(10,23);
	fflush(stdin);
	scanf("%d",&p.age);
	gotoxy(15,26);
	fflush(stdin);
	scanf("%c",&p.ch);
	fflush(stdin);gotoxy(22,29);
	scanf("%[^\n]",p.disease);
}
void newrecord1()
{
	  char q;
	 fflush(stdin);
	 gotoxy(25,33);
	scanf("%c",&q);
	switch(q)
	{
		case '1':
			{      	gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Generalphysician");
			       strcpy(p.department,"General Physician");
			       gotoxy(5,39);
				printf("Room no:");
				fflush(stdin);
				scanf("%d",&p.roomno);
			       //	getch();

				break;

			}
		case '2':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("E.N.T.");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("302");
			       strcpy(p.department,"E.N.T");
				p.roomno=302; getch();
				break;
			}
			case '3':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Cardiologist");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("509");
			       strcpy(p.department,"cardiologist");
				p.roomno=509; getch();
				break;
			}
			case '4':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Dermatologist");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("406");
			       strcpy(p.department,"Dermatologist");
				p.roomno=406; getch();
				break;
			}

			case '5':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Gastroenteroiogist");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("308");
			       strcpy(p.department,"Gastroentrologist");
				p.roomno=308; getch();
				break;
			}
			case '6':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Pediatrician");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("207");
			       strcpy(p.department,"Padiatrician");
				p.roomno=207; getch();
				break;
			}
			case '7':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("EYE Specialist");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("102");
			       strcpy(p.department,"EYE Specialist");
				p.roomno=102; getch();
				break;
			}
			case '8':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Nephrologist");
			       gotoxy(5,39);
			       printf("Room no:");
			       printf("109");
			       strcpy(p.department,"Nephrologist");
				p.roomno=109; getch();
				break;
			}
			case '9':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("General Surgeon");
			       strcpy(p.department,"General Surgeon");
			       gotoxy(5,39);
				printf("Room no:");
				fflush(stdin);
				scanf("%d",&p.roomno);
			       //	getch();
				break;
			}
			case '10':
			{      gotoxy(5,36);
			       printf("Reff.Specialist:");
			       printf("Accumpunturist");
			       strcpy(p.department,"Accumpunturist");
			       gotoxy(5,39);
				printf("Room no:");
				fflush(stdin);
				scanf("%d",&p.roomno);

				//  getch();
				break;
			}
		default:
			{
			gotoxy(5,36);
			printf("Reff.Specialist:");
			fflush(stdin);
			scanf("%[^\n]",p.department);
			gotoxy(5,39);
			printf("Room no:");
			fflush(stdin);
			scanf("%d",&p.roomno);

			return;
			}
	}
}

void displaydepartment()
{
	int i;
	gotoxy(48,14);
	printf(":Specialists:");
	gotoxy(47,15);
	printf("---------------");
	gotoxy(70,14);
	printf("Room No.");
	gotoxy(67,15);
	printf("----------");
	gotoxy(48,17);
	printf("1.General Physician");
	gotoxy(70,17);
	printf("201,202");
	gotoxy(48,19);
	printf("2.E.N.T");
	gotoxy(70,19);
	printf("302");
	gotoxy(48,21);
	printf("3.Cardiologist");
	gotoxy(70,21);
	printf("509");
	gotoxy(48,23);
	printf("4.Dermatologist");
	gotoxy(70,23);
	printf("406");
	gotoxy(48,25);
	printf("5.Gastroenterologist");
	gotoxy(70,25);
	printf("308");
	gotoxy(48,27);
	printf("6.Pediatrician");
	gotoxy(70,27);
	printf("207");
	gotoxy(48,29);
	printf("7.EYE Specialist");
	gotoxy(70,29);
	printf("102");
	gotoxy(48,31);
	printf("8.Nephrologist");
	gotoxy(70,31);
	printf("109");
	gotoxy(48,33);
	printf("9.General Surgeon");
	gotoxy(70,33);
	printf("407,408");
	gotoxy(70,35);
	printf("412,413");
	gotoxy(48,37);
	printf("10.Accupuncturist");
	gotoxy(70,37);
	printf("123,119");
	for(i=14;i<=45;i++)
	{
		gotoxy(46,i);
		printf("|");
	}
}
void print()
{
	gotoxy(29,10);
	printf("DISPLAYING RECORDS");
	gotoxy(28,11);
	printf("--------------------");
	gotoxy(10,14);
	printf("Patient no:");gotoxy(21,14);
	printf("%d",p.sn);gotoxy(10,17);
	printf("Name:");gotoxy(15,17);
	printf(" %s",p.name);gotoxy(10,20);
	printf("Address:");gotoxy(18,20);
	printf(" %s",p.address);gotoxy(10,23);
	printf("Age:");gotoxy(15,23);
	printf("%d",p.age);gotoxy(10,26);
	printf("Sex:");gotoxy(14,26);
	printf(" %c",p.ch);gotoxy(10,29);
	printf("Date of Reg.:");gotoxy(24,29);
	printf("%s",p.date);gotoxy(10,32);
	printf("Room no:");gotoxy(18,32);
	printf(" %d",p.roomno);gotoxy(10,35);
	printf("Department:");gotoxy(21,35);
	printf(" %s",p.department);gotoxy(10,38);
	printf("Category:");gotoxy(19,38);
	printf(" %s",p.category);

}
void edit1()
{
	int i,k;
	gotoxy(10,41);
	printf("Details:");gotoxy(18,41);
	printf(" %s",p.recommendation);gotoxy(10,45);(4);
	printf("Press");(15+128);
	printf(" `Enter'");(4);
	printf(" for financial records");
	getch();
	system("cls");
	mainscreen();
	(14);     gotoxy(20,8);
	printf("The list of expenditure of patient no:");
	printf("%d",p.sn);
	for(z=0,i=0,k=11;p.testfee[z]!=0;i++,z++)
	{
		gotoxy(20,k);
		printf("%d)",i+1);
		printf(" %s",&p.test[z][0]);gotoxy(40,k);
		printf("Rs.%0.2f",p.testfee[z]);
		k=k+2;
	}
	gotoxy(20,k+2);
	printf("Total charge=");
	printf("Rs.%0.2f",p.totalfee);
	gotoxy(20,k+4);
	printf("Total Deposited:");
	printf("Rs.%0.2f",p.balance);
	if(p.totalfee>p.balance)
	{
		 gotoxy(20,k+6);
		printf("Total money to pay=");

		printf("%0.2f",p.totalfee-p.balance);
	}
	else
	{
		 gotoxy(20,k+6);
		printf("Total money to return=");

		printf("%0.2f",p.balance-p.totalfee);

	}
}
void switch1()
{
	int x,i;
	float d,lk;
	char v;
	label2:
	gotoxy(30,15);
	printf("Enter");gotoxy(30,18);
	printf("1.Add Details");
	gotoxy(30,20);
	printf("2.Change Specialist");
	gotoxy(30,22);
	printf("3.Deposit balance");gotoxy(30,24);
	printf("4.Add test");
	gotoxy(30,26);
	printf("5.Return to main menu");
	gotoxy(35,39);
	fflush(stdin);
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		      {
			system("cls");
			mainscreen();
			gotoxy(31,10);
			printf("ADDING DETAILS");
			gotoxy(30,11);
			printf("----------------");
			gotoxy(15,25);

			printf("Previous Details:");
			gotoxy(32,25);
			printf(" %s ",p.recommendation);
			gotoxy(15,28);
			strcat(p.recommendation,"-> ");
			printf("New Details:");
			fflush(stdin);
			scanf("%[^\n]",string);
			strcat(p.recommendation,string);
			break;
		      }
		case 2:
		      {
			system("cls");
			mainscreen();
			displaydepartment();
			gotoxy(28,10);
			printf("CHANGING SPECIALIST");
			gotoxy(27,11);
			printf("---------------------");
			gotoxy(5,20);

			printf("Previous Specialist:");
			gotoxy(26,20);
			printf(" %s ",p.department);
			gotoxy(5,27);
			printf(":Enter the new changed Specialist;");
			gotoxy(5,33);
			printf("Reff. Specialist no:");
			newrecord1();
			break;
		      }
		case 3:
		      {
		       system("cls");
		       mainscreen();
		       gotoxy(28,10);
		       printf("DEPOSITING MONEY");
		       gotoxy(27,11);
		       printf("---------------------");
		       gotoxy(20,20);

		       printf("Deposited balance: Rs.");
		       fflush(stdin);
		       scanf("%f",&d);
		       p.balance=p.balance+d;
		       break;
		      }
		case 4:
		      {
		       system("cls");
		       mainscreen();
		       displaytest();
		       gotoxy(45,13);(3);
		       printf("Type `esc' tn content to stop");
		       gotoxy(45,15);
		       printf("Contents");gotoxy(70,15);
			printf("Rs.");lk=0;
		       for(i=17;1;i++,z++)
		       {
				gotoxy(45,i);
				fflush(stdin);
				printf("%c ",16);
				scanf("%s",&p.test[z][0]);
				if(strcmp(&p.test[z][0],"esc")==0)
				{       labelh:
					gotoxy(48,i+3);
					printf("Paid/Unpaid (p/u):");
					scanf("%c",&v);
					if(v=='p')
					{
					p.balance=p.balance+lk;
					}
					else if(v!='u')
					{       gotoxy(48,i+2);
					       //	(4+128);
					       //	cprintf("Wrong Choice");
						goto labelh;
					}
					break;
				}
				gotoxy(70,i);
				fflush(stdin);
				scanf("%f",&p.testfee[z]);
				lk=lk+p.testfee[z];
				p.totalfee=p.totalfee+p.testfee[z];
				i++;
		       }
		       break;
		      }
		case 5:
		      {
				       return;
		      }

		default:
		       {
		       system("cls");
		       mainscreen();gotoxy(30,13);
		       printf("Wromg choice");
		       goto label2;
		       }

	}
	system("cls");
	mainscreen();
	goto label2;
}
void editrecord()
{
	int y,x;
	gotoxy(20,20);
	printf("Enter the patient `record no' or `Full name': ");gotoxy(25,24);

	fflush(stdin);
	scanf("%[^\n]",string);
	string[0]=toupper(string[0]);
	y=atoi(string);
	system("cls");
	mainscreen();
	if((fp=fopen(fn1,"rb+"))==NULL)
	{
		printf("\n cannot open the record file 1");
		getch();
		exit(1);
	}
      // rewind(fp);
	while(fread(&p,sizeof(p),1,fp))
	{
	if((p.sn==y)||(strcmp(p.name,string)==0))
		{
			print();
			edit1();gotoxy(22,46);
			printf("Press `1'to edit or add and any key togo to main menu");
			fflush(stdin);
			scanf("%d",&x);
			if(x==1)
			{
			  system("cls");
			  mainscreen();
			  switch1();
			}
			else
			return;
			rewind(fp);
			fseek(fp,(p.sn-1)*sizeof(p),SEEK_SET);
			fwrite(&p,sizeof(p),1,fp);
			fclose(fp);
			break;
		}
	}

	if(p.sn!=y)
	{
		gotoxy(22,25);
		printf("There is no record available"); gotoxy(22,30);

		printf("Press Enter to continue:"); getch();
	}


}
void displaytest()
{       int i;
	gotoxy(50,10);
	printf("::ADDING SERVICES::");gotoxy(45,11);
    printf("----------------------------");
	gotoxy(9,10);(6);
	printf(":PRICE LIST:");

	gotoxy(4,11);
	printf("---------------------");
	gotoxy(5,14);
	printf("1.X-Ray");
	gotoxy(30,14);
	printf("Rs. 300.00");
	gotoxy(5,16);
	printf("2.Ultra-sound");
	gotoxy(30,16);
	printf("Rs. 500.00");
	gotoxy(5,18);
	printf("3.C.T.Scan");
	gotoxy(30,18);
	printf("Rs.1800.00");
	gotoxy(5,20);
	printf("4.TC,DC,HB");
	gotoxy(30,20);
	printf("Rs.  90.00");
	gotoxy(5,22);
	printf("5.Urine R/E");
	gotoxy(30,22);
	printf("Rs.  80.00");
	gotoxy(5,24);
	printf("6.Blood C/S");
	gotoxy(30,24);
	printf("Rs. 250.00");
	gotoxy(5,26);
	printf("7.Biliribin D/T");
	gotoxy(30,26);
	printf("Rs. 200.00");
	gotoxy(5,28);
	printf("8.Stool Test");
	gotoxy(30,28);
	printf("Rs.  60.00");
	gotoxy(5,30);
	printf("9.Bed Charge");
	gotoxy(30,30);
	printf("Rs. 150.00");
	gotoxy(5,32);
	printf("10.Sugar Test");
	gotoxy(30,32);
	printf("Rs. 400.00");

	for(i=10;i<=46;i++)
	{
		gotoxy(41,i);
		printf("|");
	}
}
void mainscreen()
{
	int i,j;
	system("cls");
	for(i=2,j=2;i<rw;j++)
	{
		if(j>15)
		j=2;
		(j);
		gotoxy(i,2);
		printf("%c",15);
		gotoxy(i,cl-1);
		printf("%c",15);
		i++;

	}
	for(i=2,j=2;i<cl;i++,j++)
	{
		if(j>15)
		j=2;
		(j);
		gotoxy(2,i);
		printf("%c",15);
		gotoxy(rw-1,i);
		printf("%c",15);

	}
	gotoxy(25,4);
	printf("SITS NARHE HOSPITAL");
	gotoxy(28,6);
	printf("NARHE, PUNE");
	gotoxy(27,7);
	printf("--------------");
}