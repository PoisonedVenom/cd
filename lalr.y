
%{
   #include<stdio.h>
   int yywrap();
   int yyparse();
   int yylex(void);
   void yyerror(char* s);
%}
%token NUMBER
%left '+' '-'
%left '*' '/'

%%
S:E {printf("\nans is %d",$$);}
;
E: E'+'E {$$=$1+$3;}
   |E'-'E {$$=$1-$3;}
   |E'*'E {$$=$1*$3;}
   |E'/'E {
      if($3==0)yyerror("divide by zero");
      else $$=$1/$3;
   }
   |NUMBER {$$=$1;}
   ;
%%
int main(){
   yyparse();
}
int yywrap(){
   return 1;
}
void yyerror (char *s) {
   fprintf (stderr, "%s\n", s);
 }