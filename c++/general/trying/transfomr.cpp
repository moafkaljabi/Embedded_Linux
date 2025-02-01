template <class InputIterator, class OutputIterator, class UnaryOperator>
  OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op)
{
  while (first1 != last1) {
    *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
    ++result; ++first1;
  }
  return result;
}
