#include<iostream>
#include<vector>
using namespace std;

struct node{
    int v;
    char c;
};

int valid(string s1,string s2, string result,node nodelist[],int n){
    int val1=0,val2=0,res=0;
    for(int i=0; i<s1.size(); i++){
        for (int j = 0; j < n; j++)
        {
            if(s1[i] == nodelist[j].c){
                val1 = val1*10 + nodelist[j].v;
                break;
            }
        }
    }
    for(int i=0; i<s2.size(); i++){
        for (int j = 0; j < n; j++)
        {
            if(s2[i] == nodelist[j].c){
                val2 = val2 *10 + nodelist[j].v;
                break;
            }
        }
    }
    for(int i=0; i<result.size(); i++){
        for (int j = 0; j < n; j++)
        {
            if(result[i] == nodelist[j].c){
                res = res*10 + nodelist[j].v;
                break;
            }
        }
    }
    if(val1+val2==res) return 1;

    return 0;
}
int solve(string s1,string s2, string result,node nodelist[],int n,int m,vector<int>visited){
    if (n == m){
        if(valid(s1,s2,result,nodelist,n)){
            for(int i=0; i<n;i++){
                cout<<nodelist[i].c<<"="<<nodelist[i].v<<endl;
            }
            return 1;
        }
    }
    for(int i=0; i<10; i++){
        if(!visited[i]){
            visited[i]=1;
            nodelist[m].v= i;
            if(solve(s1,s2,result,nodelist,n,m+1,visited)) return 1;
            visited[i]=0;
        }
    }
    return 0;
}
int main(){
    string s1 = "SEND";
    string s2 = "MORE";
    string result = "MONEY";
   
    vector<int> fre(26,0);

    for (int i = 0; i < s1.size(); i++)
    {
        fre[s1[i]-'A']++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        fre[s2[i]-'A']++;
    }
    for (int i = 0; i < result.size(); i++)
    {
        fre[result[i]-'A']++;
    }
    int n=0;
    for (int i = 0; i < 26; i++)
    {
        if(fre[i]) n++;
    }
    node nodelist[n];
    for (int i = 0, j=0; i < 26 && j<n; i++)
    {  
        if(fre[i]){
            nodelist[j].c = i+'A';
            j++;
        }
    }
    vector<int> visited(10,0);
    if(!solve(s1,s2,result,nodelist,n,0,visited)) cout<<"No Solution";
    return 0;
}