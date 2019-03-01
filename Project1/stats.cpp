#include "stats.h"
using namespace std;
using namespace main_savitch_2C;
namespace main_savitch_2C{
statistician::statistician(){
  reset();
  }

void statistician::next(double r){
      total += r;

  if(count == 0){
    tinyest = r;
    largest = r;
    }
  if(r < tinyest){
    tinyest = r;
    }
  if(r > largest){
    largest = r;
    }
count++;
}

void statistician::reset(){
  count = 0;
  total = 0;
  tinyest = 0;
  largest = 0;
  }

int statistician::length() const{
  return count;
  }

double statistician::sum() const{

  return total;
  }

double statistician::mean() const{
  double M;
  M = total/count;
  return M;
  }
  double statistician::minimum() const{

  return tinyest;
  }
  double statistician::maximum() const{

  return largest;
  }

  statistician operator +(const statistician& s1, const statistician& s2){
      statistician A;
      A.tinyest = 0;
      A.largest = 0;
      if(s1.length() == 0){
        return s2;
      }
      if(s2.length() == 0){
        return s1;
        }
      A.total = s1.sum() + s2.sum();
      A.count = s1.length() + s2.length();
      if(s1.maximum() > s2.maximum()){
        A.largest = s1.maximum();
        }else{
          A.largest = s2.maximum();
          }
      if(s1.minimum() < s2.minimum()){
        A.tinyest = s1.minimum();
        }else{
          A.tinyest = s2.minimum();
         }
    return A;
    }

  statistician operator *(double scale, const statistician& s){
    statistician B;
    if(scale < 0){
      B.count = s.length();
      B.total = s.sum()*scale;
      B.tinyest = s.maximum()*scale;
      B.largest = s.minimum()*scale;
      return B;
      }

    B.total = s.sum()*scale;
    B.count = s.length();
    B.tinyest = s.minimum()*scale;
    B.largest = s.maximum()*scale;
    return B;

    }
  bool operator ==(const statistician& s1, const statistician& s2){
    if(s1.length()== 0 &&  s2.length() == 0){
      return true;
      }
    if(s1.length() == s2.length()){
    if(s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum() && s1.sum() == s2.sum() && s1.mean() == s2.mean()){
      return true;
      }
    }
      return false;

    }

  }