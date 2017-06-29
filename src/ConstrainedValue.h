// Copyright (c) 2017 Philippe Julien
// Email    : pjulien21@gmail.com
// LinkedIn : https://www.linkedin.com/in/philippe-julien-a80b2442/
// License  : MIT
//            https://opensource.org/licenses/MIT

#ifndef CONSTRAINEDVALUE_H
#define CONSTRAINEDVALUE_H

#include <limits>

                             // ConstrainedValue<T>
                             //
                             // Represents a value constrained between two bounds.
                             // The bounds can be specified in any order and any  
                             // value within those bounds is acceptable. This can 
                             // improve readability and ensures that there is always
                             // at least one acceptable value within the bounds.
                             // 
                             // Whenever the value or the bounds change, the value
                             // is then clamped against the bounds interval. This
                             // means that the value actually kept might differ
                             // from the value assigned. That's why some member
                             // functions returns the actual value after modification.
                             // 
                             // [NOTES]
                             //    - This class has been designed with base types in mind.
                             //      (References and move semantics not considered)
template <typename T>
class ConstrainedValue
   {
   public:
                             // Create a default initialized value without constraints
      ConstrainedValue()
         {

         }
                             // Create a value without constraints
                             // Constructor is explicit to avoid nasty implicit
                             // conversions which may cause strange behaviors for now.
      explicit ConstrainedValue(T value)
         : mValue(value)
         {

         }
                             // Create a value constrained between bound1 and bound2
      ConstrainedValue(T value,
                       T bound1,
                       T bound2)
         : mValue(value)
         {
         ApplyConstraints(bound1, bound2);
         }

      T MaxValue() const
         {
         return (mMaxValue);
         }

      T MinValue() const
         {
         return (mMinValue);
         }

      T SetConstraints(T bound1,
                       T bound2)
         {
         return ApplyConstraints(bound1, bound2);
         }

      T SetValue(T value)
         {
         mValue = value;
         return ClampValue();
         }

      ConstrainedValue<T>& operator=(T value)
         {
         mValue = value;
         ClampValue();
         return (*this);
         }

      ConstrainedValue<T>& operator+=(T value)
         {
         mValue += value;
         ClampValue();
         return (*this);
         }

      ConstrainedValue<T>& operator-=(T value)
         {
         mValue -= value;
         ClampValue();
         return (*this);
         }

      ConstrainedValue<T>& operator*=(T value)
         {
         mValue *= value;
         ClampValue();
         return (*this);
         }

      ConstrainedValue<T>& operator/=(T value)
         {
         mValue /= value;
         ClampValue();
         return (*this);
         }

                             // Allow implicit conversion to the underlying type
                             // to allow transparent use as if this was a simple
                             // T value. Simply return the actual value;
      operator T() const
         {
         return (mValue);
         }

   private:
      T ApplyConstraints(T bound1,
                         T bound2)
         {
         if (bound1 < bound2)
            {
            mMinValue = bound1;
            mMaxValue = bound2;
            }
         else
            {
            mMinValue = bound2;
            mMaxValue = bound1;
            }

         return ClampValue();
         }

      T ClampValue()
         {
         if (mValue < mMinValue)
            mValue = mMinValue;
         else if (mValue > mMaxValue)
            mValue = mMaxValue;

         return (mValue);
         }

      T mValue {};
      T mMinValue = std::numeric_limits<T>::min();
      T mMaxValue = std::numeric_limits<T>::max();
   };

#endif
