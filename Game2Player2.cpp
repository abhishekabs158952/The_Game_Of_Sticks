#include<iostream>
#include<ctype.h>
using namespace std;
//int n;
struct node{
    int data;
    int label;
    int win;
    struct node *next1;
    struct node *next2;
    struct node *next3;
};
int chooseBest(struct node *var){
    int best=1;
    if(var->data==0){
        if(var->label%2==0)
            return 1;
        else
            return 0;
    }else{
        struct node *var2;
        struct node *var3;
        struct node *var4;
        var2=(struct node *)malloc(sizeof(struct node));
        var3=(struct node *)malloc(sizeof(struct node));
        var4=(struct node *)malloc(sizeof(struct node));

        var2->data=var->data-1;
        var2->label=var->label+1;
        var2->next1=NULL;
        var2->next2=NULL;
        var2->next3=NULL;
        var->next1=var2;

        var3->data=var->data-2;
        var3->label=var->label+1;
        var3->next1=NULL;
        var3->next2=NULL;
        var3->next3=NULL;
        var->next2=var3;

        var4->data=var->data-3;
        var4->label=var->label+1;
        var4->next1=NULL;
        var4->next2=NULL;
        var4->next3=NULL;
        var->next3=var4;

        if(var->label%2==0){
            var2->win=0;
            var3->win=0;
            var4->win=0;
        }else{
            var2->win=1;
            var3->win=1;
            var4->win=1;
        }

        if(var->data-1>=0){
            var2->win=chooseBest(var2);
        }
        if(var->data-2>=0){
            if(var->label%2==0){
                if(var2->win!=1)
                    var3->win=chooseBest(var3);
            }else{
                if(var2->win!=0)
                    var3->win=chooseBest(var3);
            }
        }
        if(var->data-3>=0){
            if(var->label%2==0){
                if(var2->win!=1&&var3->win!=1)
                    var4->win=chooseBest(var4);
            }else{
                if(var2->win!=0&&var3->win!=0)
                    var4->win=chooseBest(var4);
            }
        }
        if(var->label%2==0){
            if(var2->win==1||var3->win==1||var4->win==1)
                var->win=1;
            else
                var->win=0;
        }else{
            if(var2->win==1&&var3->win==1&&var4->win==1&&var->label!=0)
                var->win=1;
            else
                var->win=0;
        }
        //cout<<var2->win<<" "<<var3->win<<" "<<var4->win<<" \n";
        if(var->label==0){
            if(var->win==1){
                if(var2->win==1)
                    return 1;
                else if(var3->win==1)
                    return 2;
                else
                    return 3;
            }else {
                return 1;
            }
        }else{
            if(var->win==1)
                return 1;
            else
                return 0;
        }
    }
    return 0;
}
int fastgame(int n,int turn,int mode){
    if(n<=0){
        return turn;
    }else if(turn==0||mode==1){
        int choose=1;
        if((n-1)%4==1){
            //cout<<"in 1 ";
            choose=1;
        }else if((n-2)%4==1){
            //cout<<"in 2 ";
            choose=2;
        }else if((n-3)%4==1){
            //cout<<"in 3 ";
            choose=3;
        }
        cout<<"A.I "<<turn+1<<"     : "<<choose<<"\n";
        if(turn==1)
            turn=0;
        else
            turn=1;
        return fastgame(n-choose,turn,mode);
    }else{
        int choose=1;
        cout<<"Your Turn : ";
        cin>>choose;
        if(turn==1)
            turn=0;
        else
            turn=1;
        return fastgame(n-choose,turn,mode);
    }
}
int game(int n,int turn,int mode){
    if(n>30){
        return fastgame(n,turn,mode);
    }
    int choose;
    if(n<=0){
        return turn;
    }else if(turn==0||mode==1){
        struct node *var;
        var=(struct node *)malloc(sizeof(struct node));
        var->data=n;
        var->label=0;
        var->win=0;
        var->next1=NULL;
        var->next2=NULL;
        var->next3=NULL;
        choose=chooseBest(var);
        cout<<"A.I "<<turn+1<<"     : "<<choose<<"\n";
        if(turn==1)
            turn=0;
        else
            turn=1;
        return game(n-choose,turn,mode);
    }else{
        cout<<"Your Turn : ";
        cin>>choose;
        if(turn==1)
            turn=0;
        else
            turn=1;
        return game(n-choose,turn,mode);
    }
}
int main(){
    int t;
    cout<<"No of testCase : ";
    cin>>t;
    while(t--){
        int caseNo,n,turn,winner;
        cout<<"Case Type : ";
        cin>>caseNo;
        if(caseNo!=1&&caseNo!=2&&caseNo!=3){
            while(caseNo!=1&&caseNo!=2&&caseNo!=3){
                cout<<"Choose correct case\n";
                cout<<"Case Type : ";
                cin>>caseNo;
            }
        }else if(caseNo==1){
            cout<<"1 : 14  \n2: 21  \n3: 53 \n";
            int caseNo2;
            cout<<"Case Type : ";
            cin>>caseNo2;
            if(caseNo2!=1&&caseNo2!=2&&caseNo2!=3){
                while(caseNo2!=1&&caseNo2!=2&&caseNo2!=3){
                    cout<<"Choose correct caseNo2\n";
                    cout<<"Case Type : ";
                    cin>>caseNo2;
                }
            }else if(caseNo2==1){
                n=14;
                turn=rand()%2;
                winner=game(n,turn,1);
            }else if(caseNo2==2){
                n=21;
                turn=rand()%2;
                winner=game(n,turn,1);
            }else if(caseNo2==3){
                n=53;
                turn=rand()%2;
                winner=game(n,turn,1);
            }
        }else if(caseNo==2){
            cout<<"n : ";
            cin>>n;
            //turn=1;
            turn=rand()%2;
            winner=game(n,turn,0);
        }else if(caseNo==3){
            cout<<"n : ";
            cin>>n;
            turn=rand()%2;
            winner=game(n,turn,1);
        }
        cout<<"Winner Player "<<winner+1<<"\n\n\n";
    }
}
