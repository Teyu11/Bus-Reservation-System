/*******************************************************************************************************************
C++ PROJECT  FOR BUS RESERVATION SYSTEM

THIS SYESTEM HAS THE FOLLOWING CAPABILITIES
1 STORES A SET OF PRE-DEFINED BUS ROUTES AND BUS FARE AND TIMINGS
2.DISPLAYS AVAILABLE BUS ROUTES
3.CUSTOMER CAN  DO THE  TICKET BOOKING.
4.THE RESERVATION DETAILS ARE STORED IN INFO.DAT FILE
5.CUSTOMER CAN CANCEL THE RESERVATION
6.YOU CAN PRINT THE TICKET
7.YOU CAN GET THE PASSENGER INFORMATION ON A PARTICULAR BUS

*******************************************************************************************************************/
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
//THIS CLASS CONTAIN ALL THE FUNCTIONS RELATED TO TICKET

class TRAVEL
{
public:
    void INFORMATION( void );
    void RESERVATION( void );
    int  RESERVED( int , int , int , int , int );
    int  AVAIL( int , int , int , int );
    void DELETION( void );
    void LIST_OF_PASS( void );
    void TKT_PRINT( void );
    void MAINMENU( void );
private:
    int  busno,
	 seatno;
    char name[ 26 ],
	 sex;
    int  age,
	 fare;
    int  dd,
	 mm,
	 yy;
}    ;
char *place[6]={"Mumbai","Pune","Bangalore","Jaipur","Goa","Silvasa"};
int price[6]={100,220,1000,175,500,730};
char *ptime[6]={"10:30AM","11:30AM","12:30PM","1:30PM","2:30PM"};
//THIS FUNCTION DISPLAY THE PASSENGER INFORMATION


void  TRAVEL::TKT_PRINT( void )
{
    clrscr( );
    int bno    = 0,
	found  = 0,
	sno,
	d,
	m,
	y;
    cout << "\n\t\t\t APEEJAY TRAVELS PVT LTD.";
    cout << "\n Bus 1:Navi Mumbai to Mumbai     <fare Rs.100>";
    cout << "\n Bus 2:Navi Mumbai to Pune        <fare Rs.220>";
    cout << "\n Bus 3:Navi Mumbai to Bangalore   <fare Rs.175>";
    cout << "\n Bus 4:Navi Mumbai to Jaipur      <fare Rs.1000>";
    cout << "\n Bus 5:Navi Mumbai to Goa         <fare Rs.500>";
    cout << "\n Bus 6:Navi Mumbai to Silvasa     <fare Rs.730>";
    do
    {
	cout << "\n\n Enter the Bus no.(1/2/3/4/5/6):";
	cin >> bno;
    } while( bno < 1 || bno > 6 );
    cout << "\n Enter the date of the reserved ticket:";
    cin >> d;
    cout << "\n Enter the month:";
    cin >> m;
    cout << "\n Enter the year:";
    cin >> y;
    cout << "\n Enter the seat no.:";
    cin >> sno;
    if( sno > 60 || sno < 1 || !RESERVED( bno, d, m, y, sno ) )
    {
	cout << "\n\n\nsorry! seat not reserved";
	getch( );
	return;
    }
    fstream  file;
    file.open( "INFO.DAT", ios::in );
    while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if( ( dd == d && mm == m && yy == y ) && bno == busno && sno == seatno )
	{
	    found = 1;
	    clrscr( );
	    gotoxy( 5, 5 );

	    cout << "**********************************************************************";
	    gotoxy( 28, 7 );
	    cout << "Apeejay Travels Pvt Ltd";
	    gotoxy( 10, 9 );
	    cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y;
	    gotoxy( 10, 10 );
	    cout << "SEAT NO.:" << sno << "\t\t\tTIME:" << ptime[ bno - 1 ];
	    gotoxy( 10, 12 );
	    cout << "FROM:Navi Mumbai" << "\t\t\tTO:" << place[ bno - 1 ];
	    gotoxy( 10, 14 );
	    cout << "PASSENGER NAME:" << name;
	    gotoxy( 10, 16 );
	    cout << "PASSENGER AGE:  " << age << "\t\t\tGender:" << sex;
	    gotoxy( 10, 18 );
	    cout << "TOTAL FARE  :" << price[ bno - 1 ];
	    gotoxy( 5, 20 );
	    cout << "************************************************************************";
	    gotoxy( 1, 25 );
	    cout << "Press any key to continue...";
	    getch( );
	    break;
	}
    }
    file.close( );
    if( !found )
    {
	cout << "\n Passenger record not found";
	getch( );
    }
}
//This function gives the list of all the passenger
void  TRAVEL::LIST_OF_PASS( void )
{
    clrscr( );
    int  bno    = 0,
	 found  = 0,
	 row    = 8;
    char ch;
    cout << "\n\t\t\t APEEJAY TRAVELS PVT LTD.";
    cout << "\n Bus 1:Navi Mumbai to Mumbai     <fare Rs.100>";
    cout << "\n Bus 2:Navi Mumbai to Pune        <fare Rs.220>";
    cout << "\n Bus 3:Navi Mumbai to Bangalore   <fare Rs.175>";
    cout << "\n Bus 4:Navi Mumbai to Jaipur      <fare Rs.1000>";
    cout << "\n Bus 5:Navi Mumbai to Goa         <fare Rs.500>";
    cout << "\n Bus 6:Navi Mumbai to Silvasa     <fare Rs.730>";
    do
    {
	cout << "\n\nEnter the Bus no.(1/2/3/4/5/6):";
	cin >> bno;
    } while( bno < 1 || bno > 6 );
    do
    {
	cout << "\n Do you want date wise report(y/n):";
	cin >> ch;
    }
	while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );
    int d  = 0,
	m  = 0,
	y  = 0;
    if( toupper( ch ) == 'Y' )
    {
	cout << "\nEnter date(dd):";
	cin >> d;
	cout << "\nEnter month(mm):";
	cin >> m;
	cout << "\nEnter year(yy):";
	cin >> y;
    }
    clrscr( );
    gotoxy( 25, 1 );
    cout << "LIST OF THE PASSENGERS ";
    gotoxy( 24, 2 );
    cout << "\n***********************************************************************"
     << endl;
    gotoxy( 1, 3 );
    cout << " BUS NO.:" << bno << "\tFrom: Navi Mumbai  TO:" << place[ bno - 1 ];
    gotoxy( 2, 5 );
    cout << "SEAT NO.   PASSENGER NAME               GENDER    AGE    DATE ";
    gotoxy( 2, 6 );
    cout << "**************************************************************************"
     << endl;
    fstream  file;
    file.open( "INFO.DAT", ios::in );
    while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if( busno == bno )
	{
	    if( ( toupper( ch ) == 'N' )
		 || ( ( toupper( ch ) == 'Y' ) && ( dd == d && mm == m && yy == y ) ) )
	    {
		found = 1;
		gotoxy( 5, row );
		cout << seatno;
		gotoxy( 14, row );
		cout << name;
		gotoxy( 43, row );
		cout << sex;
		gotoxy( 50, row );
		cout << age;
		gotoxy( 61, row );
		cout << dd << "/" << mm << "/" << yy;
		row++;
		if( row == 25 )
		{
		    getch( );
		    for( int  i  = 8; i <= 24; i++ )            //          < >
		    {
			gotoxy( 1, i );
			clreol( );
		    }
		    row = 8;
		}
	    }
	}
    }
    file.close( );
    if( !found )
    {
	cout << "\n\No reservation for the bus no. " << bno;
	getch( );
	return;
    }
    //  goto(23,25)
    cout << "\nPress any key to continue..............";
    getch( );
}

int  TRAVEL::AVAIL( int  bno, int  d, int  m, int  y )
{
    fstream  file;
    file.open( "INFO.DAT", ios::in );
    int avail  = 0,
	count  = 0;
    while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if( dd == d && mm == m && yy == y && bno == busno )
	    count++;
    }
    if( count < 60 )
	avail = 1;
    file.close( );
    return avail;
}

int  TRAVEL::RESERVED( int  bno, int  d, int  m, int  y, int  sno )
{
    fstream  file;
    file.open( "INFO.DAT", ios::in );
    int reserved  = 0;
    while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if( dd == d && mm == m && yy == y && bno == busno && sno == seatno )
	{
	    reserved = 1;
	    break;
	}
    }
    file.close( );
    return reserved;
}


/* FUNCTION TO RESERVE TICKET
 This function takes bus no, date of reservation and checks the ticket availability
 Each bus has a seating capacity of 60 seats
 The fucntion checks if the age of passenger is less than 5. No tickets are issued if the age is less than 5
 once the tickets are reserved, it will prompt the user to save the record */

void  TRAVEL::RESERVATION( void )
{
    clrscr( );
    int  bno,
	 sno,
	 pfare,
	 page;
    char ch,
	 pname[ 26 ],
	 psex;
    cout << "\n\t\t\t APEEJAY TRAVELS";
    cout << "\n Bus 1:Navi Mumbai to Mumbai <fare Rs.100>";
    cout << "\n Bus 2:Navi Mumbai to Pune        <fare Rs.220>";
    cout << "\n Bus 3:Navi Mumbai to Bangalore   <fare Rs.175>";
    cout << "\n Bus 4:Navi Mumbai to Jaipur <fare Rs.1000>";
    cout << "\n Bus 5:Navi Mumbai to Goa         <fare Rs.500>";
    cout << "\n Bus 6:Navi Mumbai to Silvasa     <fare Rs.730>";
    do
    {
	cout << "\n\nEnter the Bus no.(1/2/3/4/5/6):";
	cin >> bno;
    } while( bno < 1 || bno > 6 );
    int d,
	m,
	y;
    cout << "\nEnter the date for reservation :";
    cin >> d;
    cout << "\nEnter month:";
    cin >> m;
    cout << "\nEnter year:";
    cin >> y;
    if( !AVAIL( bno, d, m, y ) )
    {
	cout << "\n\n\nsorry! seat not available";
	getch( );
	return;
    }
    cout << "\nEnter the seat no.:";
    cin >> sno;
    if( sno > 60 || sno < 1 || RESERVED( bno, d, m, y, sno ) )
    {
	cout << "\n\n\nsorry! seat already reserved";
	getch( );
	return;
    }
    cout << "\n Enter name of passenger:";
    gets( pname );
    do
    {
	cout << "Enter Gender of passenger(M/F):";
	cin >> psex;
    }
	while( toupper( psex ) != 'M' && toupper( psex ) != 'F' );
    cout << "Enter age:";
    cin >> page;
    if( page <= 5 )
    {
	cout << "\n No ticket is required upto the age of 5";
	getch( );
	return;
    }
    clrscr( );
    gotoxy( 5, 5 );
    cout << "**********************************************************************" << endl;
    gotoxy( 28, 7 );
    cout << "Apeejay Travels Pvt Ltd.";
    gotoxy( 10, 9 );
    cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y;
    gotoxy( 10, 10 );
    cout << "SEAT NO.:" << sno << "\t\t\tTIME:" << ptime[ bno - 1 ];
    gotoxy( 10, 12 );
    cout << "FROM:Navi Mumabi" << "\t\t\tTo:" << place[ bno - 1 ];
    gotoxy( 10, 14 );
    cout << "Passenger Name:" << pname;
    gotoxy( 10, 16 );
    cout << "Passenger Age:  " << page << "\t\tGender:" << psex;
    gotoxy( 10, 18 );
    cout << "Total Fare   :" << price[ bno - 1 ];
    gotoxy( 5, 20 );
    cout << "**********************************************************************";
    cout << "\n\n\n";
    do
    {
	cout << "Do you want to save ticket(y/n)";
	cin >> ch;
    }
	while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );
    if( toupper( ch ) == 'N' )
	return;
    fstream  file;
    file.open( "INFO.DAT", ios::app );
    busno  = bno;
    seatno = sno;
    strcpy( name, pname );
    sex  = psex;
    age  = page;
    fare = pfare;
    dd   = d;
    mm   = m;
    yy   = y;
    file.write( ( char * )this, sizeof( TRAVEL ) );
    file.close( );
}


/*FUNCTION TO DELETE RECORD OF THE PASSENGER */

void  TRAVEL::DELETION( void )
{
    clrscr( );
    char s;
    int  bno    = 0,
	 found  = 0,
	 sno,
	 d,
	 m,
	 y;
    char ch;
    cout << "\n\t\t\t APEEJAY TRAVELS";
    cout << "\n Bus 1:Navi Mumbai to Mumbai     <fare Rs.100>";
    cout << "\n Bus 2:Navi Mumbai to Pune        <fare Rs.220>";
    cout << "\n Bus 3:Navi Mumbai to Bangalore   <fare Rs.175>";
    cout << "\n Bus 4:Navi Mumbai to Jaipur      <fare Rs.1000>";
    cout << "\n Bus 5:Navi Mumbai to Goa         <fare Rs.500>";
    cout << "\n Bus 6:Navi Mumbai to Silvasa     <fare Rs.730>";
    do
    {
	cout << "\n\n Enter the Bus no.(1/2/3/4/5/6):";
	cin >> bno;
    } while( bno < 1 || bno > 6 );
    cout << "\nEnter the date of the reserved ticket:";
    cin >> d;
    cout << "\nEnter the month:";
    cin >> m;
    cout << "\nEnter the year:";
    cin >> y;
    cout << "\nEnter the seat no.:";
    cin >> sno;
    if( sno > 60 || sno < 1 || !RESERVED( bno, d, m, y, sno ) )
    {
	cout << "\n\n\nsorry! seat not reserved";
	getch( );
	return;
    }
    fstream  file,
	     temp;
    file.open( "INFO.DAT", ios::in );
    temp.open( "TEMP.DAT", ios::out );
    while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if( ( dd == d && mm == m && yy == y ) && ( busno == bno && seatno == sno ) )
	{
	    found = 1;
	    clrscr( );
	    gotoxy( 5, 5 );
	    cout << "************************************************************************";
	    gotoxy( 28, 7 );
	    cout << "Apeejay Travels Pvt Ltd";
	    gotoxy( 10, 9 );
	    cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y;
	    gotoxy( 10, 10 );
	    cout << "SEAT NO.:" << sno << "\t\t\tTIME:" << ptime[ bno - 1 ];
	    gotoxy( 10, 12 );
	    cout << "FROM:Navi Mumbai" << "\t\t\tTo:" << place[ bno - 1 ];
	    gotoxy( 10, 14 );
	    cout << "Passenger Name:" << name;
	    gotoxy( 10, 16 );
	    cout << "Passenger Age:  " << age << "\t\tGender:" << sex;
	    gotoxy( 10, 18 );
	    cout << "Total Fare   :" << price[ bno - 1 ];
	    gotoxy( 5, 20 );
	    cout << "*********************************************************************";
	    do
	    {
		gotoxy( 1, 25 );
		clreol( );
		cout << "Do you want to delete(y/n)";
		cin >> ch;
	    }
		while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );
	    if( toupper( ch ) == 'N' )
		temp.write( ( char * )this, sizeof( TRAVEL ) );
	}
	else
	    temp.write( ( char * )this, sizeof( TRAVEL ) );
    }
    file.close( );
    temp.close( );
    if( !found )
    {
	cout << "\nPassenger record not found";
	getch( );
	return;
    }

    if( toupper( ch ) == 'N' )
	return;
    file.open( "INFO.DAT", ios::out );
    temp.open( "TEMP.DAT", ios::in );
    while( temp.read( ( char * )this, sizeof( TRAVEL ) ) )      //  ##### write & ; error
	file.write( ( char * )this, sizeof( TRAVEL ) );
    file.close( );
    temp.close( );
}


void  TRAVEL::INFORMATION( void )
{
    clrscr( );
    gotoxy( 20, 8 );
    cout << "\n\t\t\t APEEJAY TRAVELS PVT LTD.";
    gotoxy( 4, 10 );
    cout << " There are six buses whose routes , timings and Fare are displayed below:";
    gotoxy( 4, 12 );
    cout << "\n Bus 1:Navi Mumbai to Mumbai\t<fare Rs.100>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 13 );
    cout << "\n Bus 2:Navi Mumbai to Pune\t<fare Rs.220>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 14 );
    cout
     << "\n Bus 3:Navi Mumbai to Bangalore\t<fare Rs.175>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 15 );
    cout << "\n Bus 4:Navi Mumbai to Jaipur\t<fare Rs.1000>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 16 );
    cout << "\n Bus 5:Navi Mumbai to Goa\t<fare Rs.500>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 17 );
    cout << "\n Bus 6:Navi Mumbai to Silvasa\t<fare Rs.730>\tDep Time :12:30PM Arrival 1.30PM";

    cout << "\n you can reserve ticket of any date and later on cancel the same also.";
    gotoxy( 28, 23 );
    cout << "Press any key to continue.......";
    getch( );
}
/*   MAIN FUNCTION WHICH DISPLAY MAIN MENU & CALL ALL OTHER FUNCTIONS */

void  MAINMENU( void )
{
    TRAVEL  travel;
    char    ch;
    while( 1 )
    {

	clrscr( );
	gotoxy( 15, 4 );
	cout << "******************************************************";
	gotoxy( 26, 5 );
	cout << "A";
	delay( 100 );
	cout << "p";
	delay( 100 );
	cout << "e";
	delay( 100 );
	cout << "e";
	delay( 100 );
	cout << "j";
	delay( 100 );
	cout << "a";
	delay( 100 );
	cout << "y";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "T";
	delay( 100 );
	cout << "r";
	delay( 100 );
	cout << "a";
	delay( 100 );
	cout << "v";
	delay( 100 );
	cout << "e";
	delay( 100 );
	cout << "l";
	delay( 100 );
	cout << "s";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "P";
	delay( 100 );
	cout << "v";
	delay( 100 );
	cout << "t";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "L";
	delay( 100 );
	cout << "t";
	delay( 100 );
	cout << "d";
	delay( 100 );
	cout << ".";
	cout << endl;
	cout << endl;
	delay( 100 );
	gotoxy( 15, 6 );
	cout << "******************************************************";

	gotoxy( 29, 13 );
	cout << "1::INTRODUCTION";
	gotoxy( 29, 14 );
	cout << "2::RESERVATION";
	gotoxy( 29, 15 );
	cout << "3::TICKET CANCELLATION";
	gotoxy( 29, 16 );
	cout << "4::PASSENGER LIST";
	gotoxy( 29, 17 );
	cout << "5::TICKET PRINTING";
	gotoxy( 29, 18 );
	cout << "6::QUIT";
	gotoxy( 29, 20 );
	cout << "Enter your choice::";
	ch = getch( );
	if( ch == 27 || ch == '6' )
	{
	    clrscr( );
	    int gdriver  = DETECT,
		gmode;
	    int midx,
		midy,
		ht;
	    initgraph( &gdriver, &gmode, "../bgi" );
	    midx = getmaxx( ) / 2;
	    midy = getmaxy( ) / 2;
	    setcolor( 1 );
	    settextstyle( TRIPLEX_FONT, 0, 3 );
	    settextjustify( CENTER_TEXT, CENTER_TEXT );
	    outtextxy( midx, midy, "THANK YOU PLEASE VISIT US AGAIN" );
	    break;
	}
	else
	    if( ch == '1' )
		travel.INFORMATION( );
	    else
		if( ch == '2' )
		    travel.RESERVATION( );
		else
		    if( ch == '3' )
			travel.DELETION( );
		    else
			if( ch == '4' )
			    travel.LIST_OF_PASS( );
			else
			    if( ch == '5' )
				travel.TKT_PRINT( );
    }
}

//MAIN function to call all the functions
void  main( )
{
    int gdriver  = DETECT,
	gmode;
    initgraph( &gdriver, &gmode, "../bgi" );
    setcolor( 1 );
    setbkcolor( 0 );
    settextstyle( TRIPLEX_FONT, 0, 1 );
    outtextxy( 130, 230, "Welcome to Apeejay Travels" );
    rectangle( 100, 150, 500, 300 );
    setfillstyle( 3, getmaxcolor( ) );
    pieslice( 150, 300, 0, 360, 23 );
    setfillstyle( 3, getmaxcolor( ) );
    pieslice( 450, 300, 0, 360, 23 );
    line( 100, 220, 500, 220 );
    line( 100, 170, 500, 170 );
    line( 170, 170, 170, 220 );
    line( 240, 170, 240, 220 );
    line( 310, 170, 310, 220 );
    line( 380, 170, 380, 220 );
    line( 460, 170, 460, 220 );
    line( 500, 150, 550, 300 );
    line( 500, 300, 550, 300 );
    getch( );
    closegraph( );
    MAINMENU( );
    getch( );
}
