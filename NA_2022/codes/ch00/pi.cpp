#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_INT 2147483647

void Caculate_pi()
{
  double x=2, z=2;
  int a=1, b=3;
  while (z > 1e-15)
  {
    z = z*a/b;
    x += z;
    a++;
    b += 2;
  }
  
  printf("PI = %.16f\n", x);
}

/* function: ��������λ��piֵ */  
void Caculate_pi_symbol()  
{  
    int len,i;                                      //lenΪС������  
    int numberator = 1,denominator = 3,result,carry;  
    int flag = 1,count = 0;                         //����ѭ���ı�־��ѭ���Ĵ���  
    char *pi,*temp;                                 //ָ�򱣴�piֵ����ʱ������������  
    printf("Please input the number of decimal digits: ");  
    scanf("%d",&len); 
      
    len += 2;                                       //������λ  
    if(!(pi = (char*)malloc(sizeof(char)*len)))     //���䱣��piֵ���ڴ�  
    {  
        printf("malloc memeory failed��\n");  
        exit(0);  
    }  
    if(!(temp = (char*)malloc(sizeof(char)*len)))   //���䱣������ʱֵ���ڴ�  
    {  
        printf("malloc memeory failed��\n");  
        exit(0);  
    }  
  
    for(i = 0; i < len; i++)                        //��ʼ������  
    {  
        pi[i] = temp[i] = 0;  
    }  
    pi[1] = 2;                                      //�ó�ֵ  
    temp[1] = 2;   
  
    while (flag && (++count < MAX_INT))             //int�����ֵ 2147483647  
    {  
        carry = 0;  
        for(i = len-1; i > 0; i--)                  //�ӵ�λ����λ���  
        {  
            result = temp[i] * numberator+carry;    //��ÿһλȥ�ˣ��ټ��Ͻ�λ  
            temp[i] = result % 10;                  //�������  
            carry = result / 10;                    //��λ  
        }  
  
        carry = 0;  
        for(i = 0; i < len; i++)                    //�и�λ����λ���г�������  
        {  
            result = temp[i] + carry*10;            //��ǰλ����ǰһλ������  
            temp[i] = result / denominator;         //��ǰλ����������  
            carry = result % denominator;           //��ǰλ���������ۼӵ���һλ������  
        }  
        flag = 0;                                   //�����־  
  
        for(i = len-1; i > 0; i--)                 
        {     
            result = pi[i] + temp[i];               //���������ۼӵ�result��  
            pi[i] = result % 10;                    //����һλ  
            pi[i-1] += result / 10;                 //���λ��λ  
            flag |= temp[i];                        //��temp�е���ȫΪ0,�˳�ѭ��  
        }   
        numberator++;                               //�ۼӷ���  
        denominator += 2;                           //�ۼӷ�ĸ  
    }  

    printf("Computed %d times\n\n", count);         //���ѭ������  
    printf("PI = ");  
    printf("%d.",pi[1]);  
    for(i = 2; i < len; i++)  
    {  
        if((i>2) && (i-2)%10 == 0)                  //ÿ10λС�����һ���ո�  
            printf(" ");  
        if((i>2) && (i-2)%50 == 0)                  //ÿ50λС������  
            printf("\n");   
  
        printf("%d",(int)pi[i]);                    //���һλС��  
    }  
    printf("\n");    
}  

void main()  
{  
    Caculate_pi();
    Caculate_pi_symbol();  
}  
