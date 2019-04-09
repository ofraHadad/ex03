/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    PhysicalNumber e(100, Unit::CM);
    PhysicalNumber f(30, Unit::SEC);
    PhysicalNumber g(5, Unit::TON);
    PhysicalNumber h(100, Unit::KG);
    PhysicalNumber i(15, Unit::G);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(e, "100[cm]")
    .CHECK_OUTPUT(f, "30[sec]")
    .CHECK_OUTPUT(g, "5[ton]")
    .CHECK_OUTPUT(h, "100[kg]")
    .CHECK_OUTPUT(i, "15[g]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")
    .CHECK_OUTPUT(a+e, "2.001[km]")
    .CHECK_OUTPUT(d+f, "30.5[min]")
    .CHECK_OUTPUT(g+h, "5.1[ton]")
   .CHECK_OUTPUT(i+g, "5000015[g]")
   .CHECK_EQUAL(i==g, false)
   .CHECK_EQUAL(i!=g, true)
   .CHECK_EQUAL(d==d, true)
  .CHECK_EQUAL(a>=b, true)
  .CHECK_EQUAL(i>=g, false)
  .CHECK_EQUAL(d<f, false)
  .CHECK_OUTPUT(++a, "2[km]")
  .CHECK_OUTPUT(i++, "16[g]")
   .CHECK_OUTPUT(-e, "-100[cm]")
  .CHECK_OUTPUT(+d, "30[min]")




    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)
   .CHECK_THROWS(g==f)
   .CHECK_THROWS(e!=d)
   .CHECK_THROWS(b+d)
   .CHECK_THROWS(g<=a)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    

      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "* Grade: " << grade << " *" << endl;
    return grade;
}
