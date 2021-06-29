# Segment-Tree-Generic

Syntax - Initialization
-----
This initializes the Segment Tree by taking required parameters:
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
| default_return_value  | when a range is not possible it returns this value <br> (varies with requirements) |
|  merger   | function defined in the .cpp file specifying the operation to be performed |

**merger() implementation:**
```
//for summation over the range
int merger(int a, int b){
  return a + b;
}

//for returning maximum over the range
int merger(int a, int b){
  return max(a, b);
}

//for returning gcd over the range
int merger(int a, int b){
  return __gcd(a,b);
}
```

Syntax - Query
-----
This returns the required value over the range:
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
This updates the range:
```
st.update( L, R, value );
```
Here, <br>
| Variable  | Definition |
| ------------- | ------------- |
| L  | leftmost index of the range |
| R  | rightmost index of the range |
| value | value to be added over range [L,R] |

