#include<iostream>
using namespace std;
struct  node
        {
            int data;
            struct node *next;

        };
        node *first=NULL;
        node *last=NULL;
        node *newnode;
        //node *temp;
        void create()
              {
                  int n,val;
                  cout<<"Enter Size Of The Linked List You Nedd";
                  cin>>n;
                  cout<<"Input Elements Of The List"<<endl;
                   for(int i=0;i<n;i++)
                        {   
                            cout<<"Enter Value for Element["<<i<<"]" ;
                            cin>>val;
                            newnode=new node;
                            newnode->data=val;
                            newnode->next=NULL;
                            
                             if(first==NULL)
                                  {
                                       first=newnode;
                                       last=newnode;
                                  }
                            else  
                                  {
                                        last->next=newnode;
                                         last=newnode;

                                  }
                         }
              }

     void addbeg()
             {
                int value;
                cout<<"Enter Value You Need To add At beg";
                cin>>value;
                newnode=new node;
                newnode->data=value;
                newnode->next=NULL;
                  if(first==NULL)
                       {
                        first=newnode;
                      }
                  else 
                       {
                             newnode->next=first;
                             first=newnode;
                       }
             }
      
     void addlast()
             {
                int value;
                cout<<"Enter Value You Need To add At  End";
                cin>>value;
                newnode=new node;
                newnode->data=value;
                newnode->next=NULL;
                  if(first==NULL)
                       {
                        first=newnode;
                        last=newnode;

                      }
                  else 
                       {
                             last->next=newnode;
                             last=newnode;
                       }
             }
      void del_beg()
                     {  
                     node *temp=first;
                        if(first==NULL)
                             {
                                 cout<<"Linkedlist Is Empty"<<endl;
                             }
                        else 
                             {
                                 first=first->next;

                             }
                             delete temp;
                     }
       void del_end()
                     {  
                        node *temp=last;
                        if(first==NULL)
                             {
                                 cout<<"Linkedlist Is Empty"<<endl;
                             }
                        if(first->next==NULL)
                             {
                                 delete first;
                                 first = NULL;
                                 last = NULL;
                              return;
                             }
                        else
                            {
                               temp=first;
                               while(temp->next->next!=NULL)
                                      {
                                          temp=temp->next;
                                      }
                                      delete temp->next;
                                      temp->next=NULL;
                            }
                            
                     }
      void search()
                  {
                      int value;
                      cout<<"Enter Value Who Need";
                      cin>>value;
                      int count=0;
                      node *temp=first;
                      while(temp!=NULL)
                            {
                                    if(temp->data==value)
                                        {
                                             cout<<"Element Found At The Position"<<count<<endl;
                                    

                                        }  
                                        count++;
                              temp=temp->next;
                              
                            }
                         

                  }
      void addafter()
                     {
                       int value;
                       cout<<"Enter Value Which Would To Insert After The Node";
                       cin>>value;
                       int aftervalue;
                       cout<<"Enter Value Which Node after User Insert Element";
                       cin>>aftervalue;
                       node *temp=first;
                       while(temp!=nullptr&&temp->data!=aftervalue)
                              {
                                    temp=temp->next;
                              }
                        node *newnode=new node;
                        newnode->data=value;
                        
                        newnode->next=temp->next;
                        temp->next=newnode;
                        if(temp == last)
                                    {
                                            last = newnode;
                                     }

                     }
            void addbefore()
                     {
                       
                       
                       int beforevalue;
                       cout<<"Enter Value Which Node Before User Insert Element";
                       cin>>beforevalue;
                           if(first == NULL)
                              {
                                  cout << "Linked List is Empty" << endl;
                                  return;
                              }

                           if(first->data == beforevalue)
                              {
                              addbeg();
                              return;
                              }
                       int value;
                       cout<<"Enter Value Which Would To Insert Before The Node";
                       cin>>value;
                       node *temp=first;
                       while(temp->next!=NULL&&temp->next->data!=beforevalue)
                              {
                                    temp=temp->next;
                              }
                              if(temp->next == NULL)
                              {
                                    cout << "Given node not found" << endl;
                                    return;
                              }
                        node *newnode=new node;
                        newnode->data=value;
                        
                        newnode->next=temp->next;
                        temp->next=newnode;
                        

                     }
     void display()
                  {
                     

                    if(first == NULL)
                            {
                               cout << "Linked List is Empty" << endl;
                              return;
                            }
                   node *temp=first;
                   while(temp!=NULL)
                            {
                                cout<<temp->data<<endl;
                                temp=temp->next;

                            }


                  }
      void specific_del()
                  {
                           int value;
                           cout<<"Enter Value You Need To Delete";
                           cin>>value;
                           
                            
                           if(first->data==value)
                               {  
                                   node *temp = first;
                                  first=first->next;
                                  delete temp;
                                  return;
                               }
                               node *prev = first;
                               node *temp = first->next;

                           while(temp !=NULL &&temp->data!=value)
                                  {
                                      prev = temp;
                                    temp = temp->next;
                                  }
                              // Position doesn't exist
                           if (temp == NULL)
                                 {
                                    cout << "Position does not exist" << endl;
                                    return;
                                 }
                           prev->next = temp->next;
                           delete temp;

            }
      void delete_pos()
                       {
                        int pos;
                        cout<<"Enter Position You Need To Delete";
                        cin>>pos;
                        if(pos==1)
                            {
                              node *temp=first;
                              first=first->next;
                              delete temp;
                              return ;
                            } 
                        node *prev=first;
                        node *temp=first->next;
                          int count=2;
                           while(temp !=NULL &&count!=pos)
                                  {
                                      prev = temp;
                                      
                                      temp = temp->next;
                                      count++;
                                  }
                                   prev->next = temp->next;
                                  delete temp;

                           
                       }
      void reverse_list()
                         {
                              cout<<"Display Reverse Of The List"<<endl;
                               node *current=first;
                               node  *prev=NULL;
                               node *next=NULL;
                               
                               while(current!=NULL)
                                      { 
                                        next=current->next;   //save next for the use;
                                        current->next=prev;   //assign value for the prev node
                                        prev=current;    //save prev node
                                       
                                        current=next;     //move forwawrd;
                                    }
                                       first=prev;   //save first node as last n
                                       current=first;
                                       while(current!=NULL)
                                              {
                                                cout<<current->data<<endl;
                                                current=current->next;
                                              }

                         }
        void update()
                       {
                            int pos;
                            int value;
                            cout<<"Enter Position Where You Need To Update";
                            cin>>pos;
                            cout<<"Enter Value For Update :";
                            cin>>value;
                            if(first==NULL)
                               {
                                cout<<"List Is Empty"<<endl;
                               }
                            if(pos==1)
                               {
                                   first->data=value;
                               }
                              node *temp=first;
                              int count=1;
                            while(temp!=NULL&&count!=pos)
                                   {
                                    temp=temp->next;
                                    count++;
                                   }
                            if(count!=pos)
                                   { 
                                    cout<<"Postion Is Null."<<endl;

                                   } 
                            temp->data=value;

                            
                       }
             void sort_list()
                      {
                            //sort using bubble sort method;
                            node *i=first;
                            while(i!=NULL)
                                  {
                                    node *j=i->next;    //save in j i->next  
                                    while(j!=NULL)  
                                         {
                                           if(i->data>j->data)
                                               {
                                                int temp=i->data;
                                                i->data=j->data;  //swap
                                                j->data=temp;   
                                               }
                                               j=j->next;//move to next iteration
                                         }
                                         i=i->next;   //move to next Iteration
 
                                } 
                              cout<<"Sorting Is Completed"<<endl;
                      }
                void count_node()
                    {
                           node *temp=first;
                           int count=0;
                           while(temp!=NULL)
                                 {  count++;
                                   temp=temp->next;
                                 }
                            cout<<"Total Nodes="<<count<<endl;
                            

                    }
                void find_max()  //find max element in list
                    {   
                        node*temp=first;    
                        node *max=first;
                        while(temp!=NULL)
                              {  
                                 if(max<temp)
                                  {
                                    max=temp;
                                  }
                                 temp=temp->next;
                              }
                        cout<<"Maximum Element Of The Linked List="<<max->data<<endl;

                    }
                  void find_min()
                    {   
                        node*temp=first;    
                        node *min=first;
                        while(temp!=NULL)
                              {  
                                 if(min>temp)
                                  {
                                    min=temp;
                                  }
                                 temp=temp->next;
                              }
                        cout<<"Maximum Element Of The Linked List="<<min->data<<endl;

                    }
                void find_middle()
                       {
                            if(first==NULL)
                               {
                                cout<<"Linked List Is Empty."<<endl;
                               }
                            node *mid=first;
                            node *midm=first;
                            while(midm!=NULL&&midm->next!=NULL)
                                  {
                                     mid=mid->next;
                                     midm=midm->next->next;

                                  }
                            cout<<"Middle Element Is ="<<mid->data<<endl;
                       }
            
int main()
        {
              int choice;
              do{
                  cout<<"================================================================================================================================="<<endl;
                  cout<<"================================================================================================================================="<<endl;
                  cout<<"=============================================================MAIN  MENU=========================================================="<<endl;
                  cout<<"1.Create List"<<endl;
                  cout<<"2.Add At The Beggining"<<endl;
                  cout<<"3.Add At The Last"<<endl;
                  cout<<"4.Delete At Begining"<<endl;
                  cout<<"5.Delete At The End"<<endl;
                  cout<<"6.Display List"<<endl;
                  cout<<"7.Search Element By Value"<<endl;
                  cout<<"8.Add Element After The Specific Node"<<endl;
                  cout<<"9.Add Element Before The Specific Node"<<endl;
                  cout<<"10.Delete At The Specific Element"<<endl;
                  cout<<"11.Delete At The Specific Position"<<endl;
                  cout<<"12.Display Reverse Of The Singly Linkedlist"<<endl;
                  cout<<"13.Update Node By User"<<endl;
                  cout<<"14.Sort list at Assending Order"<<endl;
                  cout<<"15.Count Total Node in Linked List"<<endl;
                  cout<<"16.Find Maximum Element IN LinkedList"<<endl;
                  cout<<"17.Find Minimum Element IN LinkedList"<<endl;
                  cout<<"18.Find Middle Node Of The LinkedList."<<endl;
                  cout<<"19.Exit"<<endl;                  
                  cout<<"================================================================================================================================="<<endl;
                  cout<<"================================================================================================================================="<<endl;
                   cout<<"Enter Your Choice";
                   cin>>choice;
                      switch(choice)
                             {
                                case 1:
                                    create();
                                    break;
                                case 2:
                                    addbeg();
                                    break;
                              case 3:
                                    addlast();
                                    break;
                              case 4:
                                    del_beg();
                                    break;
                              case 5:
                                    del_end();
                                    break;
                              case 6:
                                    display();
                                    break;
                              case 7:
                                    search();
                                    break;
                              case 8:
                                    addafter();
                                    break;
                              case 9:
                                     addbefore();
                                     break;
                              case 10:
                                     specific_del();
                                     break;
                              case 11:
                                     delete_pos();
                                     break;
                              case 12:
                                    reverse_list();
                                     break;
                              case 13:
                                      update();
                                      break;
                              case 14:
                                       sort_list();
                                       break;
                              case 15:
                                     count_node();
                                     break;
                              case 16:
                                     find_max();
                                     break;
                              case 17:
                                      find_min();
                                      break; 
                              case 18:
                                     find_middle();
                                     break;    
                              case 19:
                                    cout<<"exit"<<endl;
                                    break;
                            
                              default:
                                   cout<<"Invalid Choice"<<endl;
                             }

                }
                while(choice !=19);

        }  void find_max()
                    {   
                        node*temp=first;    
                        node *max=first;
                        while(temp!=NULL)
                              {  
                                 if(max<temp)
                                  {
                                    max=temp;
                                  }
                                 temp=temp->next;
                              }
                        cout<<"Maximum Element Of The Linked List="<<max->data<<endl;

                    }