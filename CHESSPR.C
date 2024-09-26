#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;

char board[8][8] = {
                    { ' ' , ' ' , ' ' , ' ' , 'Q' , 'C' , 'H' , 'R' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'r' , 'h' , 'c' , 'q' , ' ' , ' ' , ' ' , ' ' }
                    };

void display();
void change( int , int , int , int ) ;
void rook(int , int ) ;
void horse(int , int ) ;
void camel( int , int ) ;
void queen( int , int ) ;
void player1();
void player2();
void playerIa();
void save();
void load();
int check(int , int ) ;
int check2(int , int ) ;

main()
{
int  x = 0 ;
int vs = 1;
int loa = 0;
char ch ;
    printf( "\n\tWELCOME TO CHESS GAME" ) ;
    printf( "\n\n\t By Shreeji , Neel , Kirtan " ) ;
    printf("\n\n\t Play with IA or Player\n\n\t Your choice :( 0 = IA , 1 = Player )");
    scanf("%d",&vs);
    printf("\n\n\t Load your previous game ?\n\n\t Your choice :(0 = No , 1 = Yes )");
    scanf("%d",&loa);
    if (loa==1)
    {
        load();
    }
    
    getch();
    system( "cls" ) ;

 do
 {
 x++ ;
 system( "cls" ) ;
 display();

 if( (x%2) == 0 )
 {
        if (vs==0)
        {
            playerIa();
        }else{
            player2();
        }
 }
 else
 {
     player1();
 }
 
 printf( " \n\nPress Enter To Continue ! \n\n " ) ;

 ch = getch();
 }while( ch == 13 ) ;

}

void display()
{
    int i , j , k ;

    printf( " " ) ;
    for( i=0 ; i<8 ; i++ ) printf( "    %d" , i ) ; printf( "\n" ) ;

    for( k=0 ; k<8 ; k++ )
    {
    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k ) ;

    for( j=0 ; j<8 ; j++ ) { printf( "|| %c " , board[k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;

}

void change( int r1 , int c1 , int r2 , int c2 )
{
    char temp ;

    temp = board[r1][c1] ;
    board[r1][c1] = board[r2][c2] ;
    board[r2][c2] = temp ;

}

void rook( int r1 , int c1 )
{
    int i , j , n ;

    printf( "Available are: \n" ) ;

    n=c1;

    printf( "Horizontally: \n" ) ;

    while( board[r1][n-1] == ' ' )
    {
        if( n == 0 ) { break ; }
        printf( "%d%d , " , r1 , n-1 ) ;
        n-- ;
    }

    n=c1 ;

    while( board[r1][n+1] == ' '  && (n+1) <= 7 )
    {

        printf( "%d%d , " , r1 , n+1 ) ;
        ++n ;
    }

    printf( "\nVertically:\n" ) ;

    n = r1 ;

    while( board[n-1][c1] == ' ' && n > -1 )
    {
        printf( "%d%d , " , n-1 , c1 ) ;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ') && ( (n) <= 7 ) )
    {
        printf( "%d%d , " , n+1 , c1 ) ;
        ++n ;
    }

}

void horse( int r1 , int c1 )
{
    printf( "Available are: " ) ;


    if( board[r1+2][c1+1] == ' ' ) printf( "%d%d, " , r1+2 ,c1+1) ;
    if( board[r1+2][c1-1] == ' ' ) { if( (c1-1) > -1 ) printf( "%d%d, " , r1+2, c1-1 ) ; }

    if( board[r1+1][c1+2] == ' ' ) {  if( (c1+2) != 8 ) printf( "%d%d, " , r1+1 , c1+2 ) ; }
    if( board[r1-1][c1+2] == ' ' ) {  printf( "%d%d, " , r1-1 , c1+2 ) ; }

    if( board[r1-2][c1-1] == ' ' )
    {
        if( (c1-1) != -1 )
        printf( "%d%d, " , r1-2 , c1-1 ) ;
    }

    if( board[r1-2][c1+1] == ' ' ) printf( "%d%d, " , r1-2 , c1+1 ) ;

    if( board[r1+1][c1-2] == ' ' ) printf( "%d%d, " , r1+1 , c1-2 ) ;

    if( board[r1-1][c1-2] == ' ' )
    {
        if( (c1-2) != -1 )
            printf( "%d%d, " , r1-1 , c1-2 ) ;
    }
}


void camel( int r1 , int c1 )
{
    int a , b , c , d ;
    printf( "Available are: \n" ) ;


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        a++ ;
        b++ ;
    }

}

void queen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b ;
    printf( "Available are: " ) ;

    printf( "Horizontal: " ) ;

    while( board[r1][c1-y] == ' ' )
    {
        if( (c1-y) == -1 ) break ;
        printf( "%d%d , " , r1 , c1-y ) ;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' )
    {
        if( (c1+y) == 8 ) break ;
        printf( "%d%d , " , r1 , c1+y ) ;
        y++ ;
    }

    printf( "Vertical: " ) ;

    x = 1 ;

    while( board[r1-x][c1] == ' ' )
    {
        if( (r1-x) == -1 ) break ;
        printf( "%d%d , " , r1-x , c1 ) ;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' )
    {
        if( (r1+x) == 8 ) break ;
        printf( "%d%d , " , r1+x , c1 ) ;
        x++ ;
    }

    printf( "Diagonally: " ) ;

    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        a++ ;
        b++ ;
    }

}


void player1()
{
    int p1 , p2 , c1 , r1 , c2 , r2;

    printf( "\nPLAYER 1 - Big Case\n" ) ;
    again1:
    printf( "\nEnter Position of Element to change ( RC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
    {
        case 'R': rook( r1 , c1 ) ;
                  break ;
        case 'H': horse( r1 , c1 );
                  break ;
        case 'C': camel( r1 , c1 );
                  break ;
        case 'Q': queen( r1 , c1 ) ;
                  break ;
        default: printf("Invalid Position ! ") ; goto again1 ;
    }

    printf( "\nEnter Position of Place to Send ( RC ): " ) ;
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    change(r1,c1,r2,c2) ;
    int sav = 0;
     printf("\n\nSave your game ?\n\nYour choice :( 0 = No , 1 = Yes)");
 scanf("%d",&sav);
 if (sav==1)
 {
    save();
 }
}

void player2()
{
    int p1 , p2 , c1 , r1 , c2 , r2;

    printf( "\nPLAYER 2 - Small Case \n") ;
    again2:
    printf( "\nEnter Position of Element to change ( RC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
    {
        case 'r': rook( r1 , c1 ) ;
                  break ;
        case 'h': horse( r1 , c1 ) ;
                  break ;
        case 'c': camel( r1 , c1 ) ;
                  break ;
        case 'q': queen( r1 , c1 ) ;
                  break ;
        default: printf( "Invalid Position ! " ) ; goto again2 ;
    }


    printf( "\nEnter Position of Place to Send ( RC ): " ) ;
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    change(r1,c1,r2,c2) ;
}

void playerIa()
{
    int p1 , p2 , c1 , r1 , c2 , r2;

    printf( "\nIA - Small Case \n") ;
    again2:
    p1 = rand()% 78;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
    {
        case 'r': rook( r1 , c1 ) ;
                  break ;
        case 'h': horse( r1 , c1 ) ;
                  break ;
        case 'c': camel( r1 , c1 ) ;
                  break ;
        case 'q': queen( r1 , c1 ) ;
                  break ;
        default: printf( "" ) ; goto again2 ;
    }

    p2 = rand()% 78;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    change(r1,c1,r2,c2) ;
}

int check(int x , int y )
{
    switch( board[x][y] )
    {
    case 'r':
    case 'h':
    case 'c':
    case 'q': return 1 ; break ;
    default: return 0 ;
    }
}

int check2(int x , int y )
{
    switch( board[x][y] )
    {
    case 'R':
    case 'H':
    case 'C':
    case 'Q': return 1 ; break ;
    default: return 0 ;
    }
}
void save() {
    FILE *f = fopen("save.txt", "w"); // Ouvre le fichier en mode écriture
    if (f == NULL) {
        printf("Error when opening the file.\n");
        return;
    }

    // Parcourt le tableau 2D et écrit chaque ligne dans le fichier
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fputc(board[i][j], f); // Écrit chaque caractère
        }
        fputc('\n', f); // Ajoute un saut de ligne après chaque ligne
    }

    fclose(f); // Ferme le fichier
    printf("Successfully saved.\n");
    exit(0);
}
void load() {
    FILE *f = fopen("save.txt", "r"); // Ouvre le fichier en mode lecture
    if (f == NULL) {
        printf("Error when opening the file.\n");
        return;
    }

    // Parcourt le fichier et lit chaque caractère dans le tableau board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = fgetc(f); // Lit chaque caractère du fichier
        }
        fgetc(f); // Pour lire le saut de ligne et l'ignorer
    }

    fclose(f); // Ferme le fichier
    printf("Successfully loaded.\n");
}
