#include<cstdio>
#include<cstring>
#define MOD 100000000
using namespace std;

int m,n,maxn,top,Soil[25];//ÿ�����ص����

int main()
{
    scanf("%d%d",&m,&n); maxn=1<<n;
    int Type[maxn+10];//����ѹ�����ÿ�п��ܵ�״̬
    int f[20][maxn+10];
    for(int i=0;i<maxn;i++)
    {//�洢ÿ�п��ܵ�״̬
        if(i&(i<<1))continue;
        Type[++top]=i;
    }
    
    for(int i=1;i<=m;i++)
    for(int l=1;l<=n;l++)
    {
        int k; scanf("%d",&k);
        if(!k)Soil[i]+=1<<(n-l);//����ͼ,0��Ϊ1,��Type������������,����ʹ��λ������
        //��Ϊ�ȶ�������������أ�������������'1'�����ֵ����,���Խ���l������������ڵ�lλӦ+(1<<(n-l))
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=top;i++)
    if(!(Type[i]&Soil[1])) f[1][i]=1;
    
    for(int i=2;i<=m;i++)//��ٲ���
    for(int l=1;l<=top;l++){//��ٱ���
        if(Type[l]&Soil[i])continue;//�ж��Ƿ����
        for (int j=1;j<=top;j++){//�����һ��
            if (Type[j]&Soil[i-1]) continue;//�ж��Ƿ����
            if (Type[l]&Type[j]) continue;//�ж��Ƿ����
            f[i][l]=(f[i][l]+f[i-1][j])%MOD;
        }
    }
    
    int ans=0;
    for(int i=1;i<=top;i++)
    ans=(ans+f[m][i])%MOD;//�ۼӴ�
    
    printf("%d",ans);
    return 0;
}
