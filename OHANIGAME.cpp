    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    vector<int> v;
    int spfa[1000006];
    int spf(int x){
    	if(x<1000006){
    		return spfa[x];
    	}
    	for(int i=0;primes[i]*primes[i]<=x;i++){
    		if((x%primes[i])==0){
    			return primes[i];
    		}
    	}
    	return x;
    }
    void generate(){
    	int isprime;
    	primes.push_back(2);
    	spfa[2]=2;
    	for(int i=3;i<1000006;i++){
    		isprime=1;
    		for(int j=0;primes[j]*primes[j]<=i;j++){
    			if(i%primes[j]==0){
    				isprime=0;
    				spfa[i]=primes[j];
    				break;
    			}
    		}
    		if(isprime==1){
    			spfa[i]=i;
    			primes.push_back(i);
    		}
    	}
    }
    int num(int n){
    	int pui, factor, temp;
    	if(n==1){
    		return 1;
    	}
     
    	int isprime=1;
    	for(int j=0;primes[j]*primes[j]<=n;j++){
    		if(n%primes[j]==0){
    			isprime=0;
    			break;
    		}
    	}
    	if(isprime==0){
    		v.clear();
    		while(n!=1){
    			v.push_back(spf(n));
    			n=n/spf(n);
    		}
    		pui=1;
    		int i=0;
    		while(i<v.size()){
    			temp=1;
    			while((i+1)<v.size() && v[i+1]==v[i]){
    				temp++;
    				i++;
    			}
    			pui*=(temp+1);
    			i++;
    		}
    		return pui;
    	}
    	else{
    		return 2;
    	}
    }
    int main(){
    	generate();
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
     
    		if(n==0){
    			printf("Impossible\n");
    			continue;
    		}
     
    		n=abs(n);
     
    		printf("%d\n", num(n)-1);
     
    	}
    	return 0;
    } 