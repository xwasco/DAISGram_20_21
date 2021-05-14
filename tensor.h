#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>
#include <string>
#include <random>
#include <math.h>
#include <fstream>

#include "dais_exc.h"

#define PI 3.141592654
#define FLT_MAX 3.402823466e+38F /* max value */
#define FLT_MIN 1.175494351e-38F /* min positive value */
#define EPSILON 0.000001f  /* the rounding precision for comparing floats */


using namespace std;

class Tensor
{
private:

    float * data = nullptr; //<-- you are free to change this data structure (don't use std::vectors or std::array)

    int r = 0;  // number of rows
    int c = 0;  // number of columns
    int d = 0;  // tensor depth

public:

    /**
     * Class constructor
     * 
     * Parameter-less class constructor 
     */
    Tensor();

    /**
     * Class constructor
     * 
     * Creates a new tensor of size r*c*d initialized at value v
     * 
     * @param r
     * @param c
     * @param d
     * @param v
     * @return new Tensor
     */
    Tensor(int r, int c, int d, float v = 0.0);

    /**
     * Class distructor
     * 
     * Cleanup the data when deallocated
     */
    ~Tensor();

    /**
     * Operator overloading ()
     * 
     * if indexes are out of bound throw index_out_of_bound() exception
     * 
     * @return the value at location [i][j][k]
     */
    float operator()(int i, int j, int k) const;

    /**
     * Operator overloading ()
     * 
     * Return the pointer to the location [i][j][k] such that the operator (i,j,k) can be used to 
     * modify tensor data.
     * 
     * If indexes are out of bound throw index_out_of_bound() exception
     * 
     * @return the pointer to the location [i][j][k]
     */
    float &operator()(int i, int j, int k);

    /**
     * Copy constructor
     * 
     * This constructor copies the data from another Tensor
     *      
     * @return the new Tensor
     */
    Tensor(const Tensor& that);

    /**
     * Operator overloading ==
     * 
     * It performs the point-wise equality check between two Tensors.
     * 
     * The equality check between floating points cannot be simply performed using the 
     * operator == but it should take care on their approximation.
     * 
     * This approximation is known as rounding (do you remember "Architettura degli Elaboratori"?)
     *  
     * For example, given a=0.1232 and b=0.1233 they are 
     * - the same, if we consider a rounding with 1, 2 and 3 decimals 
     * - different when considering 4 decimal points. In this case b>a
     * 
     * So, given two floating point numbers "a" and "b", how can we check their equivalence? 
     * through this formula:
     * 
     * a ?= b if and only if |a-b|<EPSILON
     * 
     * where EPSILON is fixed constant (defined at the beginning of this header file)
     * 
     * Two tensors A and B are the same if:
     * A[i][j][k] == B[i][j][k] for all i,j,k 
     * where == is the above formula.
     * 
     * The two tensors must have the same size otherwise throw a dimension_mismatch()
     * 
     * @return returns true if all their entries are "floating" equal
     */
    bool operator==(const Tensor& rhs) const;

    /**
     * Operator overloading -
     * 
     * It performs the point-wise difference between two Tensors.
     * 
     * result(i,j,k)=this(i,j,k)-rhs(i,j,k)
     * 
     * The two tensors must have the same size otherwise throw a dimension_mismatch()
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator-(const Tensor &rhs)const;
    
     /**
     * Operator overloading +
     * 
     * It performs the point-wise sum between two Tensors.
     * 
     * result(i,j,k)=this(i,j,k)+rhs(i,j,k)
     * 
     * The two tensors must have the same size otherwise throw a dimension_mismatch()
     * 
     * @return returns a new Tensor containing the result of the operation
    */
    Tensor operator +(const Tensor &rhs)const;

    /**
     * Operator overloading *
     * 
     * It performs the point-wise product between two Tensors.
     * 
     * result(i,j,k)=this(i,j,k)*rhs(i,j,k)
     * 
     * The two tensors must have the same size otherwise throw a dimension_mismatch()
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator*(const Tensor &rhs)const;
    
    /**
     * Operator overloading /
     * 
     * It performs the point-wise division between two Tensors.
     * 
     * result(i,j,k)=this(i,j,k)/rhs(i,j,k)
     * 
     * The two tensors must have the same size otherwise throw a dimension_mismatch()
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator/(const Tensor &rhs)const;

    /**
     * Operator overloading - 
     * 
     * It performs the point-wise difference between a Tensor and a constant
     * 
     * result(i,j,k)=this(i,j,k)-rhs
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator-(const float &rhs)const;

    /**
     * Operator overloading +
     * 
     * It performs the point-wise sum between a Tensor and a constant
     * 
     * result(i,j,k)=this(i,j,k)+rhs
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator+(const float &rhs)const;

    /**
     * Operator overloading *
     * 
     * It performs the point-wise product between a Tensor and a constant
     * 
     * result(i,j,k)=this(i,j,k)*rhs
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator*(const float &rhs)const;

    /**
     * Operator overloading / between a Tensor and a constant
     * 
     * It performs the point-wise division between a Tensor and a constant
     * 
     * result(i,j,k)=this(i,j,k)/rhs
     * 
     * @return returns a new Tensor containing the result of the operation
     */
    Tensor operator/(const float &rhs)const;

    /**
     * Operator overloading = (assignment) 
     * 
     * Perform the assignment between this object and another
     * 
     * @return a reference to the receiver object
     */
    Tensor & operator=(const Tensor &other);

    /**
     * Random Initialization
     * 
     * Perform a random initialization of the tensor
     * 
     * @param mean The mean
     * @param std  Standard deviation
     */
    void init_random(float mean=0.0, float std=1.0);

    /**
     * Constant Initialization
     * 
     * Perform the initialization of the tensor to a value v
     * 
     * @param r The number of rows
     * @param c The number of columns
     * @param d The depth
     * @param v The initialization value
     */
    void init(int r, int c, int d, float v=0.0);

    /**
     * Tensor Clamp
     * 
     * Clamp the tensor such that the lower value becomes low and the higher one become high.
     * 
     * @param low Lower value
     * @param high Higher value 
     */
    void clamp(float low, float high);

    /**
     * Tensor Rescaling
     * 
     * Rescale the value of the tensor following this rule:
     * 
     * newvalue(i,j,k) = ((data(i,j,k)-min(k))/(max(k)-min(k)))*new_max
     * 
     * where max(k) and min(k) are the maximum and minimum value in the k-th channel.
     * 
     * new_max is the new maximum value for each channel
     * 
     * - if max(k) and min(k) are the same, then the entire k-th channel is set to new_max.
     * 
     * @param new_max New maximum vale
     */
    void rescale(float new_max=1.0);

    /**
     * Tensor padding
     * 
     * Zero pad a tensor in height and width, the new tensor will have the following dimensions:
     * 
     * (rows+2*pad_h) x (cols+2*pad_w) x (depth) 
     * 
     * @param pad_h the height padding
     * @param pad_w the width padding
     * @return the padded tensor
     */
    Tensor padding(int pad_h, int pad_w)const;

    /**
     * Subset a tensor
     * 
     * retuns a part of the tensor having the following indices:
     * row_start <= i < row_end  
     * col_start <= j < col_end 
     * depth_start <= k < depth_end
     * 
     * The right extrema is NOT included
     * 
     * @param row_start 
     * @param row_end 
     * @param col_start
     * @param col_end
     * @param depth_start
     * @param depth_end
     * @return the subset of the original tensor
     */
    Tensor subset(unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end, unsigned int depth_start, unsigned int depth_end)const;

    /** 
     * Concatenate 
     * 
     * The function concatenates two tensors along a give axis
     * 
     * Example: this is of size 10x5x6 and rhs is of 25x5x6
     * 
     * if concat on axis 0 (row) the result will be a new Tensor of size 35x5x6
     * 
     * if concat on axis 1 (columns) the operation will fail because the number 
     * of rows are different (10 and 25).
     * 
     * In order to perform the concatenation is mandatory that all the dimensions 
     * different from the axis should be equal, other wise throw concat_wrong_dimension(). 
     *  
     * @param rhs The tensor to concatenate with
     * @param axis The axis along which perform the concatenation 
     * @return a new Tensor containing the result of the concatenation
     */
    Tensor concat(const Tensor &rhs, int axis=0)const;


    /** 
     * Convolution 
     * 
     * This function performs the convolution of the Tensor with a filter.
     * 
     * The filter f must have odd dimensions and same depth. 
     * 
     * Remeber to apply the padding before running the convolution
     *  
     * @param f The filter
     * @return a new Tensor containing the result of the convolution
     */
    Tensor convolve(const Tensor &f)const;

    /* UTILITY */

    /** 
     * Rows 
     * 
     * @return the number of rows in the tensor
     */
    int rows()const;

    /** 
     * Cols 
     * 
     * @return the number of columns in the tensor
     */
    int cols()const;

    /** 
     * Depth 
     * 
     * @return the depth of the tensor
     */
    int depth()const;
    
    /** 
     * Get minimum 
     * 
     * Compute the minimum value considering a particular index in the third dimension
     * 
     * @return the minimum of data( , , k)
     */
    float getMin(int k)const;

    /** 
     * Get maximum 
     * 
     * Compute the maximum value considering a particular index in the third dimension
     * 
     * @return the maximum of data( , , k)
     */
    float getMax(int k)const;

    /** 
     * showSize
     * 
     * shows the dimensions of the tensor on the standard output.
     * 
     * The format is the following:
     * rows" x "colums" x "depth
     * 
     */
    void showSize()const;
    
    /* IOSTREAM */

    /**
     * Operator overloading <<
     * 
     * Use the overaloading of << to show the content of the tensor.
     * 
     * You are free to chose the output format, btw we suggest you to show the tensor by layer.
     * 
     * [..., ..., 0]
     * [..., ..., 1]
     * ...
     * [..., ..., k]
     */
    friend ostream& operator<< (ostream& stream, const Tensor & obj);

    /**
     * Reading from file
     * 
     * Load the content of a tensor from a textual file.
     * 
     * The file should have this structure: the first three lines provide the dimensions while 
     * the following lines contains the actual data by channel.
     * 
     * For example, a tensor of size 4x3x2 will have the following structure:
     * 4
     * 3
     * 2
     * data(0,0,0)
     * data(0,1,0)
     * data(0,2,0)
     * data(1,0,0)
     * data(1,1,0)
     * .
     * .
     * .
     * data(3,1,1)
     * data(3,2,1)
     * 
     * if the file is not reachable throw unable_to_read_file()
     * 
     * @param filename the filename where the tensor is stored
     */
    void read_file(string filename);

    /**
     * Write the tensor to a file
     * 
     * Write the content of a tensor to a textual file.
     * 
     * The file should have this structure: the first three lines provide the dimensions while 
     * the following lines contains the actual data by channel.
     * 
     * For example, a tensor of size 4x3x2 will have the following structure:
     * 4
     * 3
     * 2
     * data(0,0,0)
     * data(0,1,0)
     * data(0,2,0)
     * data(1,0,0)
     * data(1,1,0)
     * .
     * .
     * .
     * data(3,1,1)
     * data(3,2,1)
     * 
     * @param filename the filename where the tensor should be stored
     */
    void write_file(string filename);

};

#endif
