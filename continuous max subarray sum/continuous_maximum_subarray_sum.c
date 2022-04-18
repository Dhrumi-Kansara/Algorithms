#include <stdio.h>



int calculateCMSS(int a[],int p, int q);
int calculateCrossSum(int a[],int p, int mid,int q);
int calculateMax(int ls, int rs, int cs);

int main() {
  int a[9]={20,-25,130,-80,10,90,-43,12,-40};
  int p=0; /*first element*/
  int q=8; /*last element*/
  int sum = calculateCMSS(a,p,q);
  printf("\ncontinuous maximum sub array sun: %d", sum);
  
  return 0;
}

/*calculate continuous maximum sub array sum*/
/* time complexity T(n)*/
int calculateCMSS(int a[],int p, int q)
{
  int ls=0; /*left sum*/
  int rs=0; /*right sum*/
  int cs=0; /*cross sum*/
  int mid;
  int max=0;
  if(p==q) {
    // printf("\n p:%d q:%d a[p]:%d ", p, q, a[p]);
    return a[p];
  } 
  else {
    mid=(p+q)/2;
    // printf("\nmid:%d",mid);
    ls=calculateCMSS(a,p,mid);/* time complexity T(n/2)*/
    rs=calculateCMSS(a,mid+1,q);/* time complexity T(n/2)*/
    cs=calculateCrossSum(a, p, mid, q);/* time complexity n*/
    max=calculateMax(ls,rs,cs);
    // printf("\n p:%d q:%d ls:%d rs:%d cs:%d max:%d",p,q, ls, rs, cs, max);

    return max;
    
  }
  return 0;
}

/*calculate coross sum*/
int calculateCrossSum(int a[],int p, int mid,int q)
{
  
  int lts = 0, lbs = 0, lbsp = 0, rts = 0, rbs = 0, rbsp = 0, totalCrossSum=0;
  int i=mid,j=mid+1;

  // printf("\n cross sum");
  // printf("\n i:%d j:%d", i, j);
  

  /*calculate left total sum*/
  for(i=mid;i>=p;i--) {
    lts=lts+a[i];
    // printf("\nlts:%d lbs:%d\n",lts,lbs);
    if(lts>lbs) {
      lbs=lts;
      lbsp=i;
    }
  }

  /*calculate right total sum*/
    for(j=mid+1;j<=q;j++) {
    rts=rts+a[j];
    if(rts>rbs) {
      rbs=rts;
      rbsp=j;
    }
  }
  
  // printf("\nlbsp:%d rbsp:%d",lbsp,rbsp);
  // printf("\nlbs:%d rbs:%d",lbs,rbs);

  totalCrossSum = lbs+rbs;
  return totalCrossSum;
}


int calculateMax(int ls, int rs, int cs) {

  if(ls>rs) {
    if(ls>cs) {
      return ls;
    } else {
      return cs;
    }

  } else {
    if(rs>cs) {
      return rs;
    } else {
      return cs;
    }
  }

}

/*
  Time complexity:

  Recurrence relaction for time
  T(n)=T(n/2)+T(n/2)+n
      =2T(n/2)+n


  Time complextiy = T(n)=nlogn [everycase]
  stack space = logn
*/