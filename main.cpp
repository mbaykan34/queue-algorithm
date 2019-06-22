#include <iostream>
using namespace std;
//==================QUEUE'NUN ALABİLECEĞİ MAX BOYUT==================================
const int M=4;
//=====================QUEUE SINIF TANIMI============================================
template<class qType>
class queue{
    qType q[M];
    int tail;
    int head;
public:
    queue():tail(-1),head(-1){}   //default constructor, head ve tail'e ilk değer -1 verildi.
    void enqueue(qType x);
    qType dequeue();
    void print();
    bool isFull();
    bool isEmpty();
    int getHead(){return head;}
    int getTail(){return tail;}
};
//========================isFull() FONKSİYONU=========================================
template<class qType>
bool queue<qType>::isFull(){
    if(tail>=M-1)            return true;
    else                     return false;
}
//=======================enqueue() ÜYE FONKSİYON TANIMI===============================
template<class qType>
void queue<qType>::enqueue(qType x){
    if(head==-1) head++;          //queue'nun boş olduğu durum
    if(isFull()){
        cout<<"Queue dolu. Ekleme islemi basarisiz.\n";
    }
    else {
        q[++tail]=x;
    }
}
//===================isEmpty() FONKSİYONU==============================================
template<class qType>
bool queue<qType>::isEmpty(){
    if(tail<=-1 )      return true;
    else               return false;
}
//====================dequeue() ÜYE FONKSİYON TANIMI====================================
template<class qType>
qType queue<qType>::dequeue(){
    if(isEmpty()){
        cerr<<"Queue bos. Eleman cikarma islemi basarisiz.\n";
        return 0;
    }
   else{
    qType a=q[head];
    for(int i=0; i<tail; i++){
        q[i]=q[i+1];

    }
    tail--;
    return a;
    }
}
//=====================print() FONKSİYONU=================================================
template<class qType>
void queue<qType>::print(){
    if(head==-1)  cout<<"Queue bos.\n";
    else{
    for (int i= head; i<=tail; i++)
        cout<<q[i]<<"\n";
    }
}
//===================APPLICATION==========================================================
int main()
{
    queue<int> nesneQueue1;
    //nesne yeni kuruldu. head ve tail başlangıç durumunda -1...
    cout<<nesneQueue1.getHead()<<endl;   //-1
    cout<<nesneQueue1.getTail()<<endl;   //-1
    //2 eleman ekleyelim:
    nesneQueue1.enqueue(100);
    nesneQueue1.enqueue(200);
    //bu durumda tail ve head:
    cout<<nesneQueue1.getTail()<<endl;    //1
    cout<<nesneQueue1.getHead()<<endl;    //0
    //2 eleman daha ekleyelim:
    nesneQueue1.enqueue(300);
    nesneQueue1.enqueue(400);
    //bu durumda tail ve head:
    cout<<nesneQueue1.getTail()<<endl;   //3
    cout<<nesneQueue1.getHead()<<endl;   //0
    //eklemeye devam edelim...queue bunları almayacak...
    nesneQueue1.enqueue(500);
    nesneQueue1.enqueue(600);
    nesneQueue1.print();
    //bu durumda tail ve head:
    cout<<nesneQueue1.getTail()<<endl;   //3:eklemedi
    cout<<nesneQueue1.getHead()<<endl;   //0
    //queue'dan bir eleman alalım:
    cout<<nesneQueue1.dequeue()<<endl;   //100; queue'da 100 vardı onu aldı. ilk giren ilk çıkar.
    nesneQueue1.print();
    //tail ve head'i bir daha kontrol edelim:
    cout<<nesneQueue1.getTail()<<endl;   //2
    cout<<nesneQueue1.getHead()<<endl;   //0
    cout<<nesneQueue1.dequeue()<<endl;   //200
    cout<<nesneQueue1.dequeue()<<endl;   //300
    cout<<nesneQueue1.getTail()<<endl;   //0
    cout<<nesneQueue1.getHead()<<endl;   //0
    cout<<nesneQueue1.dequeue()<<endl;   //400
    cout<<nesneQueue1.getTail()<<endl;   //-1
    cout<<nesneQueue1.getHead()<<endl;   //0
    cout<<nesneQueue1.dequeue()<<endl;   //çıkarma işlemi başarısız.
    cout<<nesneQueue1.getTail()<<endl;   //-1
    cout<<nesneQueue1.getHead()<<endl;   //0
    nesneQueue1.print();
    nesneQueue1.enqueue(111);
    nesneQueue1.enqueue(222);
    cout<<nesneQueue1.dequeue()<<endl;   //ilk eklenen 111 çıkarılır.
    nesneQueue1.print();
    cout<<nesneQueue1.getTail()<<endl;   //0
    cout<<nesneQueue1.getHead()<<endl;   //0
    nesneQueue1.enqueue(333);
    nesneQueue1.enqueue(444);
    nesneQueue1.enqueue(555);
    nesneQueue1.print();                //222-333-444-555
    return 0;
}


/*
 * kapasitesi daha önceden tanımlanır.
 * Sıralıdır. Aynı tip verilerden oluşur.
 * Bu algoritma array'den oluşturulmuştur.
 * üye fonksiyonlar: enqueue(): tail'e yeni eleman ekler. dequeue():head'den eleman çıkarır.
 * Algoritmanın işleyişi:
 * --Yeni eleman eklendiğinde tail'e eklenir...tail ileriye doğru kaydırılır.
 * --Eleman çıkarılacağı zaman tailden çıkarılır. eleman çıkarılınca kalan elemanların pozisyonları
 * heade doğru 1 kaydırılır.
 */
