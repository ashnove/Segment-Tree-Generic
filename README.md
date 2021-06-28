# Segment-Tree-Generic

Syntax - Initialization
-----
```
SegmentTree<T> st( array, array_size, merger, default_return_value);
```
Here, <br>
| Variable  | Definition |
| ------------- | ------------- |
| st  | instance of the SegmentTree |
| T  | any data type |
| array  | input array [1-based indexing] |
| array_siz [int]  | size of the input array  |
| default_return value  | when a range is not possible it returns this value |
|  merger   | function defined the .cpp file sepcifying the operation to be performed |

**merger() implementation:**
```
//for summation over range
int merger(int a, int b){
  return a + b;
}

//for returning maximum over range
int merger(int a, int b){
  return max(a, b);
}
```

Syntax - Query
-----
```
st.query( L, R );
```
Here, <br>
| Variable  | Definition |
| ------------- | ------------- |
| L  | leftmost index of the range |
| R  | rightmost index of the range |

**Note: Indexing is 1-based** <br>

Syntax - Update
-----
```
st.update( L, R, value );
```
Here, <br>
| Variable  | Definition |
| ------------- | ------------- |
| L  | leftmost index of the range |
| R  | rightmost index of the range |
| value | value to be added over range [L,R] |

