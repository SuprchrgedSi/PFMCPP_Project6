/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(double v, const char* namePtr) : value(v) 
    {
        if (namePtr != nullptr) name = *namePtr;
        else name = "";
    }   //1

    double value;//2
    std::string name;//3
};

struct CompareClass                                //4
{
    const T* compare(const T& a, const T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;    

        std::cout << "Invalid pointer passed to compare function." << std::endl;
        return nullptr;
    }
};

struct U
{
    float float1 { 0 }, float2 { 0 };
    float squareCloseMember(const float& newFloat)      //12
    {
        std::cout << "U's float1 value: " << this->float1 << std::endl;
        float1 = newFloat;
        std::cout << "U's float1 updated value: " << this->float1 << std::endl;
        while( std::abs(this->float2 - this->float1) > 0.001f )
        {
            this->float2 += (this->float1 - this->float2)/2;
        }
        std::cout << "U's float2 updated value: " << this->float2 << std::endl;
        return this->float2 * this->float1;
    }
};

struct squareCloseClass
{
    static float squareClose(U& that, const float& newFloat )        //10
    {
        std::cout << "U's float1 value: " << that.float1 << std::endl;
        that.float1 = newFloat;
        std::cout << "U's float1 updated value: " << that.float1 << std::endl;
        while( std::abs(that.float2 - that.float1) > 0.001f )
        {
           that.float2 += (that.float1 - that.float2)/2;
        }
        std::cout << "U's float2 updated value: " << that.float2 << std::endl;
        return that.float2 * that.float1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 3.5, "Dev");                                             //6
    T t2( 6.3, "Chuck");                                             //6
    
    CompareClass f;                                            //7
    auto* smaller = f.compare(t1, t2);    
    if (smaller != nullptr)                          //8
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "mult u1's multiplied values: " << squareCloseClass::squareClose(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "squareCloseMember u2's multiplied values: " << u2.squareCloseMember(updatedValue ) << std::endl;
}
