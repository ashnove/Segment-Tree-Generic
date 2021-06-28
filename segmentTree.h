#ifndef SEGMENT_H
#define SEGMENT_H
#include <bits/stdc++.h>

namespace st_h {
template <class T> class SegmentTree {

      private:
      int n;
      T *arr;
      T *st;
      // T *lazy;
      int treeSize;
      T default_return;
      T (*merger)(T, T);

      void buildTree(int, int, int, T*);
      void update_lib(int ,int ,int ,int,int,int);
      T query_lib(int, int, int, int, int);

      public :
      SegmentTree(T*, int,T (*)(T, T), T);
      void update(int, int, T);
      T query(int, int);
};

template<class T> SegmentTree<T>::SegmentTree(T *arr, int n, T (*merger)(T, T),T default_return)
{
      this->arr = arr;
      this->n = n;
      treeSize = 4 * n + 1;
      st = new T[treeSize];
      // lazy = new T[treeSize];
      this->merger = merger;
      this->default_return = default_return;
      buildTree(1, 1, n, arr);
}

template<class T> void SegmentTree<T>::buildTree(int si, int ss, int se, T *a)
{
      if (ss == se) {
            st[si] = a[ss];
            return;
      }
      int mid = (ss + se) / 2;
      buildTree( 2 * si, ss, mid, a);
      buildTree( 2 * si + 1, mid + 1, se, a);

      st[si] = merger(st[2 * si], st[2 * si + 1]);
}

template<class T> void SegmentTree<T>::update(int update_L, int update_R, T val){
      update_lib(1, 1, n, update_L, update_R, val);
}
template<class T> void SegmentTree<T>::update_lib(int si, int ss, int se, int qs, int qe, int val)
{     
      if ( se < qs || ss > qe )return;
      if (ss >= qs && se <= qe) {
            st[si] += val * (se - ss + 1);
            return;
      }
      int mid = (ss + se) / 2;
      update_lib(2 * si, ss, mid, qs, qe, val);
      update_lib(2 * si + 1, mid + 1, se, qs, qe, val);

      st[si] = merger(st[2 * si], st[2 * si + 1]);

}

template<class T> T SegmentTree<T>::query(int query_L, int query_R){

      return query_lib(1, 1, n, query_L, query_R);
}

template<class T> T SegmentTree<T>::query_lib(int si, int ss, int se, int qs, int qe){

      if ( ss > qe || se < qs)
            return default_return ;
      if ( ss >= qs && se <= qe ) {
            return st[si];
      }

      int mid = (ss + se) / 2;
      T leftSubtree = query_lib( 2 * si, ss, mid, qs, qe );
      T rightSubtree = query_lib( 2 * si + 1, mid + 1, se, qs, qe);
      
      return (leftSubtree==default_return?rightSubtree:(rightSubtree==default_return?leftSubtree: merger(leftSubtree, rightSubtree)));
}
}

#endif