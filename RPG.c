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
	char nomea;
	int agia;
	int danoa;
	int pva;
	int defesaa;
	
	//nivel 2=b
	char nomeb;
	int agib;
	int danob;
	int pvb;
	int defesab;
	
	//nivel 3=c
	char nomec;
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
    oponente.danoa= 5;
    oponente.defesaa= 1;
    oponente.pva= 10;
    
	//nivel 2
    oponente.agib= 3;
    oponente.danob= 5;
    oponente.defesab=2;
    oponente.pvb= 15;
    
    //nivel 3
    oponente.agic= 5;
    oponente.danoc= 10;
    oponente.defesac=3;
    oponente.pvc= 15;
    
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
	setlocale(LC_ALL, "Portuguese");

	char opc2;//para selecionar arma
	char opc3;//para selecionar armadura
	int d12 = rand( ) %13+1;
	int d4 = rand( ) %5+1;
	int d42 = rand( ) %5+1;
	int d6 = rand( ) %7+1;
	
	printf("\t* Arma *\n");
	
	printf("A) Clauricune(leve)     B) Presa de Jormun(leve)     C) LightBringer(pesada)    D) Martelo de Forja(pesada)\n");
    printf("   ATQ: 10                 ATQ: 10                      ATQ: 15                    ATQ: 15\n");
    printf("   AGL: +1                 AGL: +1                      AGL: 0                     AGL: 0\n");
	
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
	
	printf("A) Armadura de couro    B) Armadura de diamante\n"); 
    printf("   DEF: 2                  DEF: 3\n");
    printf("   AGL: +1                 AGL: -1\n");
	
	printf("\nESCOLHA: ");
	scanf("%s", &opc3);
	
	switch(opc3){
		
		case 'a':
        case 'A':
        	
        	jogador.armadura= 2+jogador.constituicao;
        	break;
        
        case 'b' :
  	    case 'B' :
  	    	
  	    	jogador.armadura= 3+jogador.constituicao;
  	    	break;
  	    
  	    default:
				printf("Invalido, tente novamente");
				break;	
	}
	
}
//Função Cadastro do jogador
void Cadastrojogador(){
	
	system("cls");
	
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
		setlocale(LC_ALL, "Portuguese");
	Oponente oponente;
	
	char escolha;
	printf("Escolha o seu oponente: ");
	
	printf("\nA- Lich\t B-Skulltula\t C- Orc");
	
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
			
			printf("Orc: Uma besta humanoide sanguinária aos serviços de um senhor do escuro, desprovida de humanidade e empatia, vivendo apenas para saciar sua sede de sangue e servir ao seu mestre.\n\n");
		
	}
}

void EscolhaOponente2(){
		setlocale(LC_ALL, "Portuguese");
	Oponente oponente;
	
	char escolha2;
	
	printf("Escolha o seu oponente: ");
	
	printf("\nA- Grifo\t B- Manticora");
	
	printf("\nESCOLHA: ");
	scanf("%s", &escolha2);
	
	switch(escolha2){
		
		case 'a' :
		case 'A' :
			
			printf("Grifo: Uma Quimera de um mundo distante vivendo como um enorme abutre em busca de carne fresca ou restos, dizem que seu grito é tão devastador que pode implodir os tímpanos de seus inimigos.\n\n");
			break;
			
		case 'b' :
		case 'B' :
			
			printf("Manticora: Uma parente próxima do Grifo, porém muito mais agressiva que seu primo distante. Com seu veneno em sua peçonhenta cauda de escorpião, ela paralisa suas vítimas e as devora ainda vivas. \n\n");
		    break;
		    
		    default:
		    	printf("invalido! ");
			
	}
}


void Turno1()
{
	Oponente oponente;
	
	Jogador jogador;
	
	jogador.pv = 10;
	
	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	int pocao=0;
	int v1,v2,v3;
	int defesao;
	int defesaj;
	int defender=0;
	int d1,d2;
	
	do
	{
		if(jogador.agilidade > oponente.agia)
		{
			printf("Voce comeca\n");
			
			//turno jogador
			printf("0- Atacar\t1- Defender\t2- Usar Poção\n");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			switch(opc)
			{
				
			case 0 :
		
			danoj= jogador.forca- oponente.defesaa;
			if(danoj < 0)
			{
				oponente.pva= oponente.pva;
			}
			
			else
			{
				oponente.pva= oponente.pva - danoj;
			}
			
			break;
			
			case 1 :
			
			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;
			
			case 2 :
			
			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;	
			
				if(defesao == 1)
				{
					oponente.defesaa=oponente.defesaa/2;
					defesao = 0;
				}
			default: 
			
			printf("Invalido\n");
			
			break;
		
			} //fim turno jogador
			
			
			//turno oponente
			opcad= rand () %3;
			
			switch(opcad)
			{
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    dano= oponente.danoa- jogador.armadura;
			    
			    if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}
				
				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;
				
				case 1 :
					
				printf("Oponente usou escudo!\n");
				oponente.defesaa= oponente.defesaa*2;
				defesao = 1;
				oponente.defesaa=oponente.defesaa+rand()%6+rand()%6+rand()%6+2;
				break;
				
				case 2:
				printf("Oponente se curou!\n");
				oponente.pva=oponente.pva+rand()%6+rand()%6+rand()%6+3;
				break;
			
				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}
			
				
			}//fim turno oponente
		}
		
		else
		{
			printf("O oponente começa\n");
			
			//turno oponente
			opcad= rand () %3;
			
			switch(opcad)
			{
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    
				dano= oponente.danoa- jogador.armadura;
			    
				if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}
				
				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;
				
				case 1 :
					
				printf("Oponente usou escudo!\n");
				oponente.defesaa= oponente.defesaa*2;
				defesao=1;
				oponente.defesaa=oponente.defesaa+rand()%6+rand()%6+rand()%6+2;
				break;
				
				case 2:
				printf("Oponente se curou!\n");
				oponente.pva=oponente.pva+rand()%6+rand()%6+rand()%6+3;
				break;
			
				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}
				
			}//fim turno oponente
			
			//turno jogador
			printf("0- Atacar\t1- Defender\t2- Usar Poção");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			switch(opc)
			{
				
			case 0 :
		
			danoj= jogador.forca- oponente.defesaa;
			if(danoj < 0)
			{
				oponente.pva= oponente.pva;
			}
			
			else
			{
				oponente.pva= oponente.pva - danoj;
			}
			
			break;
			
			case 1 :
			
			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;
			
			case 2 :
			
			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;
			
			break;	
				if(defesao == 1)
				{
					oponente.defesaa=oponente.defesaa/2;
					defesao = 0;
				}
			default: 
			
			printf("Invalido");
			
			break;
			} //fim turno jogador
			
		}
		
	} while(jogador.pv > 1 && oponente.pva > 1);//fim do while
	
}//fim batalha 1

void Turno2()
{
	
	
	Oponente oponente;
	
	Jogador jogador;
	
	jogador.pv = 10;
	
	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	int pocao=0;
	int v1,v2,v3;
	int defesao;
	int defesaj;
	int defender=0;
	int d1,d2;
	
	do
	{
		if(jogador.agilidade > oponente.agib)
		{
			printf("Voce comeca\n");
			
			//turno jogador
			printf("0- Atacar\t1- Defender\t2- Usar Poção\n");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			switch(opc)
			{
				
			case 0 :
		
			danoj= jogador.forca- oponente.defesab;
			if(danoj < 0)
			{
				oponente.pvb= oponente.pvb;
			}
			
			else
			{
				oponente.pvb= oponente.pvb - danoj;
			}
			
			break;
			
			case 1 :
			
			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;
			
			case 2 :
			
			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;	
			
				if(defesao == 1)
				{
					oponente.defesab=oponente.defesab/2;
					defesao = 0;
				}
			default: 
			
			printf("Invalido\n");
			
			break;
		
			} //fim turno jogador
			
			
			//turno oponente
			opcad= rand () %3;
			
			switch(opcad)
			{
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    dano= oponente.danob- jogador.armadura;
			    
			    if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}
				
				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;
				
				case 1 :
					
				printf("O oponente usou escudo!\n");
				oponente.defesab= oponente.defesab*2;
				defesao = 1;
				oponente.defesab=oponente.defesab+rand()%6+rand()%6+rand()%6+2;
				break;
				
				case 2:
				printf("O oponente se curou!\n");
				oponente.pvb=oponente.pvb+rand()%6+rand()%6+rand()%6+3;
				break;
			
				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}
			
				
			}//fim turno oponente
		}
		
		else
		{
			printf("O oponente começa\n");
			
			//turno oponente
			opcad= rand () %3;
			
			switch(opcad)
			{
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    
				dano= oponente.danob- jogador.armadura;
			    
				if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}
				
				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;
				
				case 1 :
					
				printf("O oponente usou escudo!\n");
				oponente.defesab= oponente.defesab*2;
				defesao=1;
				oponente.defesab=oponente.defesab+rand()%6+rand()%6+rand()%6+2;
				break;
				
				case 2:
				printf("O oponente se curou!\n");
				oponente.pvb=oponente.pvb+rand()%6+rand()%6+rand()%6+3;
				break;
			
				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}
				
			}//fim turno oponente
			
			//turno jogador
			printf("0- Atacar\t1- Defender\t2- Usar Poção");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			switch(opc)
			{
				
			case 0 :
		
			danoj= jogador.forca- oponente.defesab;
			if(danoj < 0)
			{
				oponente.pvb= oponente.pvb;
			}
			
			else
			{
				oponente.pvb= oponente.pvb - danoj;
			}
			
			break;
			
			case 1 :
			
			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;
			
			case 2 :
			
			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;
			
			break;	
				if(defesao == 1)
				{
					oponente.defesab=oponente.defesab/2;
					defesao = 0;
				}
			default: 
			
			printf("Invalido");
			
			break;
			} //fim turno jogador
			
		}
		
	} while(jogador.pv > 1 && oponente.pvb > 1);//fim do while
	
}//fim batalha 5

void Turno3()
{
	
	
	Oponente oponente;
	
	Jogador jogador;
	
	jogador.pv = 10;
	
	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	int pocao=0;
	int v1,v2,v3;
	int defesao;
	int defesaj;
	int defender=0;
	int d1,d2;
	
	do
	{
		if(jogador.agilidade > oponente.agic)
		{
			printf("Voce comeca\n");
			
			//turno jogador
			printf("0- Atacar\t1- Defender\t2- Usar Poção\n");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			switch(opc)
			{
				
			case 0 :
		
			danoj= jogador.forca- oponente.defesac;
			if(danoj < 0)
			{
				oponente.pvc= oponente.pvc;
			}
			
			else
			{
				oponente.pvc= oponente.pvc - danoj;
			}
			
			break;
			
			case 1 :
			
			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;
			
			case 2 :
			
			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;	
			
				if(defesao == 1)
				{
					oponente.defesac=oponente.defesac/2;
					defesao = 0;
				}
			default: 
			
			printf("Invalido\n");
			
			break;
		
			} //fim turno jogador
			
			
			//turno oponente
			opcad= rand () %3;
			
			switch(opcad)
			{
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    dano= oponente.danoc- jogador.armadura;
			    
			    if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}
				
				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;
				
				case 1 :
					
				printf("O oponente usou escudo!\n");
				oponente.defesac= oponente.defesac*2;
				defesao = 1;
				oponente.defesac=oponente.defesac+rand()%6+rand()%6+rand()%6+2;
				break;
				
				case 2:
				printf("O oponente se curou!\n");
				oponente.pvc=oponente.pvc+rand()%6+rand()%6+rand()%6+3;
				break;
			
				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}
			
				
			}//fim turno oponente
		}
		
		else
		{
			printf("O oponente começa\n");
			
			//turno oponente
			opcad= rand () %3;
			
			switch(opcad)
			{
				
				case 0 : 
				
				printf("Voce foi atacado!\n");
			    
				dano= oponente.danob- jogador.armadura;
			    
				if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}
				
				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;
				
				case 1 :
					
				printf("O oponente usou escudo!\n");
				oponente.defesac= oponente.defesac*2;
				defesao=1;
				oponente.defesac=oponente.defesac+rand()%6+rand()%6+rand()%6+2;
				break;
				
				case 2:
				printf("O oponente se curou!\n");
				oponente.pvc=oponente.pvc+rand()%6+rand()%6+rand()%6+3;
				break;
			
				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}
				
			}//fim turno oponente
			
			//turno jogador
			printf("0- Atacar\t1- Defender\t2- Usar Poção");
			printf("ESCOLHA: ");
			scanf("%d", &opc);
			
			switch(opc)
			{
				
			case 0 :
		
			danoj= jogador.forca- oponente.defesac;
			if(danoj < 0)
			{
				oponente.pvc= oponente.pvc;
			}
			
			else
			{
				oponente.pvc= oponente.pvc - danoj;
			}
			
			break;
			
			case 1 :
			
			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;
			
			case 2 :
			
			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;
			
			break;	
				if(defesao == 1)
				{
					oponente.defesac=oponente.defesac/2;
					defesao = 0;
				}
			default: 
			
			printf("Invalido");
			
			break;
			} //fim turno jogador
			
		}
		
	} while(jogador.pv > 1 && oponente.pvc > 1);//fim do while
	
}//fim batalha 6

void Batalhas()
{
	printf("* Desafio 1 *\n");
	
	EscolhaOponente1();
	
	Turno1();
		if (jogador.pv > oponente.pva)
	{
		Nivel();
		printf("\n");
		
		printf("* Desafio 2 *\n");
		EscolhaOponente2();
		Turno2();
		
		if(jogador.pv > oponente.pvb)
		{
			Nivel();
			printf("\n");
			
			printf("* Desafio 3 *\n");
			printf(" Voce chegou ao nivel final, derrote o Cerberus!");
			
			Turno3();
			
			if(jogador.pv > 1)
			{
				printf("Voce completou todos os desafios e venceu o jogo");
				
			}
			
			else
			{
				printf("Derrota\n");
			}
		}
		
		else
		{
				printf("Derrota\n");
		}
	}
	
	else
	{
		printf("Derrota\n");
	}
}

//**

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
					
					Batalhas();
				
					break;
				
				default:
				
				printf("Invalido, tente novamente! ");
				
				break;	
				
			}
		}
	}
}