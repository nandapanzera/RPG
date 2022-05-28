#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

//Dados do jogador
typedef struct jogador{
	
	//status básico
	char nome[50];
	int pv;
	int forca;
	int constituicao;
	int agilidade;
	int destreza;
	int arma;
	int armadura;
	int nivel;
	
}Jogador;

Jogador jogador;

//Dados do oponente
typedef struct oponente{
	
	//nivel 1=a
	int agia;
	int danoa;
	int pva;
	int defesaa;
	
	//nivel 2=b
	int agib;
	int danob;
	int pvb;
	int defesab;
	
	//nivel 3=c
	int agic;
	int danoc;
	int pvc;
	int defesac;
	
	
}Oponente;

Oponente oponente;

//funçao cadastro oponente
void CadastroOponente(){
	
	//nivel 1
    oponente.agia= 1;
    oponente.danoa= 1;
    oponente.defesaa= 1;
    oponente.pva= 10;
    
	//nivel 2
    oponente.agib= 2;
    oponente.danob= 2;
    oponente.defesab= 2;
    oponente.pvb= 20;
    
    //nivel 3
    oponente.agic= 3;
    oponente.danoc= 3;
    oponente.defesac= 3;
    oponente.pvc= 30;
    
}

//Função linha de asterisco
char Linha()
{
	int k;
	for(k = 0; k < 20; k++)
		printf("*");
}

//função historia
void Historia()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n");
	
	Linha();
	
	printf("\n\t* História *\n");
	

	printf("História de Mundo: O fluxo do espaço-tempo se desestabilizou após uma entidade multiversal surgir em um universo pacato. Com o choque de várias dimensões e realidades, um enorme labirinto foi formado contendo 6 seres de universos distintos. Cabe a você, o sétimo sobrevivente tentar escapar enquanto enfrenta temíveis oponentes.\n\n ");

    printf("\n");
}

//função arma
void Equipamentos(){

	char opc2;//para selecionar arma
	char opc3;//para selecionar armadura
	int d12 = rand( ) %13+1;
	int d4 = rand( ) %5+1;
	int d42 = rand( ) %5+1;
	int d6 = rand( ) %7+1;
	
	printf("\t* Arma *\n");
	
	printf("A- Clauricune (arma leve)\t B- Presa de Jormun (arma leve)");
	printf("\nC- Martelo de forja (arma pesada)\t D- Lightbringer (arma pesada)");
	
	printf("\nESCOLHA: ");
	scanf("%s", &opc2);
	switch (opc2){
		
		case 'a':
		case 'A':
		case 'b':
		case 'B':
	        
	        jogador.arma = 10+jogador.destreza+d6+d4+d42;
		    break;
			    
		case 'c':
		case 'C':
		case 'd':
		case 'D':
			
			jogador.arma= 15+(1.5*jogador.forca)+d12;
			break;
			
			
			default:
				printf("Invalido, tente novamente");
				break;
	}
	printf("\n");
	
	Linha();
	
	printf("\n\t* Armadura *\n");
	
	printf("A-\t B-");
	
	printf("\nESCOLHA: ");
	scanf("%s", &opc3);
	
	switch(opc3){
		
		case 'a':
        case 'A':
        	
        	jogador.armadura= 10+jogador.constituicao;
        	break;
        
        case 'b' :
  	    case 'B' :
  	    	
  	    	jogador.armadura= 15+jogador.constituicao;
  	    	break;
  	    
  	    default:
				printf("Invalido, tente novamente");
				break;	
	}
	
}

//Função Cadastro do jogador
void Cadastrojogador(){
	
	
	Linha();
	
	printf("\n\t* Status Basico *\n");
	
	printf("Informe seu nome: ");
	scanf("%s", &jogador.nome);
	fflush(stdin);
	
	printf("\n");
	
    Linha();
    
    printf("\n\t* Atributos *\n");
    
    printf("Nota: ");
    printf("A soma dos atributos deve ser igual a 15 pontos\n");
    
    printf("Informe a forca: ");
    scanf("%d", &jogador.forca);
    
    printf("Informe a constiticao: ");
    scanf("%d", &jogador.constituicao);
    
    printf("Informe a agilidade: ");
    scanf("%d", &jogador.agilidade);
    
    printf("Informe a destreza: ");
    scanf("%d", &jogador.destreza);
    
    Linha();
    
    printf("\n");
    
    Equipamentos();
    
    printf("\n");
    
    system("cls");
    
}

//funçao menu
void menu() {
	int escolha;
	
	Linha();
	
    printf("\n\t MENU\n");
    
    Linha();
    
    printf("\n");
    printf("Bem vindo jogador! Para continuar escolha uma opcao:\n");
    printf("1- Historia\n");
    printf("2- Comecar o jogo.\n");
    printf("3- Sair.\n");
   
}

//função level up

void Nivel(){
	
	printf("Parabens! voce completou o desefio e subiu de nível!\n");
	
	jogador.nivel= jogador.nivel+1;
	
	printf("* Nivel %d *", jogador.nivel);
	
	jogador.pv= jogador.pv + jogador.constituicao;
	
	printf("Aqui esta o seu premio: %d pv", jogador.pv);
	
}

void EscolhaOponente1(){
	
	Oponente oponente;
	
	char escolha;
	
	printf("Escolha o seu oponente: ");
	
	printf("\nA- Lich\t B-Skulltula\t C- Cão Infernal");
	
	printf("\nESCOLHA: ");
	scanf("%s", &escolha);
	
	switch(escolha){
		
		case 'a' :
		case 'A' :
			
			printf("Lich: Morto-vivo que as histórias dizem já ter sido um grande mago de um século perdido. Hoje, é apenas um amontoado de ossos e carne ambulante amaldiçoado com a morte eterna.\n\n");
			
			break;
			
		case 'b' :
		case 'B' :
			
			printf("Skulltula: Uma das infames crias de Laracna, esta aranha monstruosa tem um enorme desejo por crânios humanos para servir de sua toca. Porém é bastante comum vê-la com crânios infantis.\n\n");
			
			
			break;
			
		case 'c' :
		case 'C' :
			
			printf("Cão Infernal: Não se sabe ao certo de onde ou como eles surgiram, apenas que esta espécie está a serviço de Thanatos e andam no mundo dos vivos com a missão de trazer as almas dos culpados para seu mestre.\n\n");
			
	}
}

void Batalha1(){
	
	Oponente oponente;
	
	Jogador jogador;
	
	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	
	//turno oponente
	if(oponente.agia>= jogador.agilidade){
		
	printf(" O oponente comeca");
	
		do{
			opcad= rand () %3;
			
			switch(opcad){
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    dano= oponente.danoa- jogador.armadura;
			   jogador.pv= jogador.pv- dano;
				break;
				
				case 1 :
					
				printf("O oponente usou escudo!\n");
				oponente.defesaa= oponente.defesaa*2;
				
				break;
				
				case 2:
				
				printf("poçao");
				break;	
			} while{
			
			if(oponente.pva>=0){
				
				printf("Voce perdeu");
			}
			
			else if()
			}
			
			
		}
		
	else{
		
		printf("Voce comeca: ");
		
		while (oponente.pva > 0 || jogador.pv > 0){
			
			//turno jogador
			printf("0- Atacar\t1- Defender/t2- Usar Poção");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			if(opc==0){
				
				danoj= jogador.forca- oponente.defesaa;
				
				oponente.pva= oponente.pva- danoj;
			}
			
			else if(opc==1){
				
				jogador.armadura= jogador.armadura*2;
			}
			
			else{
				
				printf("ok");
			}
			
			//turno oponente
			//atacar
			if(opcad==0){
				
			dano= oponente.danoa- jogador.armadura;
			jogador.pv= jogador.pv- dano;	
				
			}
			
			//defender
			else if(opcad==1){
				
				oponente.defesaa= oponente.defesaa*2;
				
			}
			
			//pocao
			else{
				
				printf("ok");
				
			}
		}
	}
	
	
}
//**************************************************************************************

int main()
{
	int escolha;
	
	for(;;){
		
		menu();
		printf("ESCOLHA: ");
		scanf("%d", &escolha);
		
		if(escolha == 3){
			
			break;
		}
		
		else{
			
			switch(escolha){
				
				case 1:
				    Historia();
				    break;
				
				case 2:
					Cadastrojogador();
					EscolhaOponente1();
					Batalha1();
					
					break;
				
				default:
				
				printf("Invalido, tente novamente! ");
				
				break;	
				
			}
		}
	}
}