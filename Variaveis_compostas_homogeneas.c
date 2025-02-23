#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char candidato[50][30], topCandidato[30];
    int pe[4], ac[5],pp[10], eb[3], maior1[50], maior2[50], maior3[50], maior4[50], menor1[50], menor2[50], menor3[50], menor4[50];
    int qntd, i, j, k;
    int soma1[50], soma2[50], soma3[50], soma4[50];
    float medPE[50], medAC[50], medPP[50], medEB[50];
    float nf[50], trocaNF;

    printf("\nEscolha a quantidade de candidatos (Min: 2 Max: 50): ");
    scanf("%d",&qntd);
    while(qntd<2 || qntd>50){
        printf("\nQuantidade de candidatos invalida, digite novamente: ");
        scanf("%d",&qntd);
    }

    for(i=0;i<qntd;i++){
        j=0; maior1[i]=0; maior2[i]=0; maior3[i]=0; maior4[i]=0; menor1[i]=10; menor2[i]=10; menor3[i]=10; menor4[i]=10;
        soma1[i] = soma2[i] = soma3[i] = soma4[i] = 0;
        printf("\nNome do %do candidato: ",i+1);
        scanf("%s", candidato[i]);
        printf("\nNotas PE(4):\n\n");
        while(j<4){
            scanf("%d",&pe[j]);
            if(pe[j]>maior1[i]){
                maior1[i]=pe[j];
            }
            if(pe[j]<menor1[i]){
                menor1[i]=pe[j];
            }
            soma1[i]+=pe[j];
            j++;
        }
        printf("\nNotas AC(5):\n\n"); j=0;
        while(j<5){
            scanf("%d",&ac[j]);
            if(ac[j]>maior2[i]){
                maior2[i]=ac[j];
            }
            if(ac[j]<menor2[i]){
                menor2[i]=ac[j];
            }
            soma2[i]+=ac[j];
            j++;
        }
        printf("\nNotas PP(10):\n\n"); j=0;
        while(j<10){
            scanf("%d",&pp[j]);
            if(pp[j]>maior3[i]){
                maior3[i]=pp[j];
            }
            if(pp[j]<menor3[i]){
                menor3[i]=pp[j];
            }
            soma3[i]+=pp[j];
            j++;
        }
        printf("\nNotas EB(3):\n\n"); j=0;
        while(j<3){
            scanf("%d",&eb[j]);
            if(eb[j]>maior4[i]){
                maior4[i]=eb[j];
            }
            if(eb[j]<menor4[i]){
                menor4[i]=eb[j];
            }
            soma4[i]+=eb[j];
            j++;
        }

        medPE[i] = (soma1[i]-maior1[i]-menor1[i])/2.0;
        medAC[i] = (soma2[i]-maior2[i]-menor2[i])/3.0;
        medPP[i] = (soma3[i]-maior3[i]-menor3[i])/8.0;
        medEB[i] = (soma4[i]-maior4[i]-menor4[i])/1.0;
        nf[i] = ((medPE[i]*0.3)+(medAC[i]*0.1)+(medPP[i]*0.4)+(medEB[i]*0.2));
    }

    for(i=0;i<qntd-1;i++) {
        for(j=i+1;j<qntd;j++){
            if(nf[i] < nf[j]){
                trocaNF = nf[i];
                nf[i] = nf[j];
                nf[j] = trocaNF;

                for(k=0;k<30;k++){
                    topCandidato[k] = candidato[i][k];
                    candidato[i][k] = candidato[j][k];
                    candidato[j][k] = topCandidato[k];
                }
            }
        }
    }

    printf("\nOs melhores 15 candidatos sao:\n\n");
    for(i=0;i<qntd && i<15;i++){
        printf("%d. %s - Nota Final: %.2f\n", i + 1, candidato[i], nf[i]);
    }

    return 0;
}