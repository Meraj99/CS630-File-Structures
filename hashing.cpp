#include<iostream>

using namespace std;

struct ll{
	int data;
	struct ll * link;
};

typedef ll ll;

class OHash{
public:
	int n,ar[100];
	ll data[100];
	OHash(int n){
		this->n=n;

		for(int i=0;i<n;i++){
			data[i].data=0;
			data[i].link=NULL;
		}
	}

	void getData(){
		cout<<"Enter the data." << endl;
		for(int i=0;i<n;i++)
			cin>>ar[i];
	}
	void disp(){
		ll *ptr=NULL;
		for(int i=0;i<n;i++){
			cout<<"Count: "<<data[i].data<<"\t";
			ptr=data[i].link;
			while(ptr!=NULL){
				cout<<ptr->data<<" ";
				ptr=ptr->link;
			}
			cout<<endl;
		}
	}

	void hash(){
		int pos;
		ll * ptr;
		for(int i=0;i<n;i++){
			pos=(ar[i]%n);
			data[pos].data++;
			ptr=data+pos;
			while(ptr->link!=NULL){
				ptr=ptr->link;
			}
			ll *newnode=new ll;
			newnode->data=ar[i];
			newnode->link=NULL;
			ptr->link=newnode;
		
		}


	}

	void find(int key){
		int pos,flag=0;
		ll* ptr;
		pos=(key%n);
		
		ptr=data+pos;

		while(ptr->link!=NULL){
			ptr=ptr->link;
			if(ptr->data==key){
				cout<<"Key found." << endl;
				flag=1;
				break;
			}

		}
		if(!flag) cout<<"Key not found." << endl;


	}

};


class CHash{
public:
	int n,ar[100],data[100];	
	CHash(int n){
		this->n=n;
		for(int i=0;i<n;i++)
			data[i]=-1;
	}

	void getData(){
		cout<<"Enter the data." << endl;
		for(int i=0;i<n;i++)
			cin>>ar[i];
	}

	void disp(){
		cout<<"Hashing table:" << endl;
		for(int i=0;i<n;i++)
			cout<<data[i]<<" ";
		cout<<endl;

	}

	void hash(){
		int limit=0,j,pos;
		for(int i=0;i<n;i++){
			limit=0;
			j=0;
			while(limit<(n+1)){
				pos=((ar[i]+j)%n);
				if(data[pos]==-1){
					data[pos]=ar[i];
					break;
				}
				limit++;
				j++;
			}
		
		}

	}

	void find(int key){
		int j,pos, flag = 0;
		while(j<=n){
			pos=((key+j)%n);
			if(data[pos]==key){
				cout<<"Key found." << endl;
				flag = 1;
				break;
			}
			j++;
		}
		if(!flag) cout<<"Key not found." << endl;

	}
};


int main(){

    int n,key;
    cout<<"Enter the value of n." << endl;
    cin>>n;

    //closed hashing
    CHash h(n);
    h.getData();
    h.hash();
    h.disp();

    cout<<"Enter the key to search (closed hashing)." << endl;
    cin>>key;
    h.find(key);

    //open hashing
    OHash h2(n);
    h2.getData();
    h2.hash();
    h2.disp();

    cout<<"Enter the key to search (open hashing)." << endl;
    cin>>key;
    h2.find(key);

    return 0;
}
