#include <iostream>
#include <string.h>
#include "date.h"
#include "date.cpp"
#include "address.h"
#include "address.cpp"
#include "person.h"
#include "person.cpp"
#include "patient.h"
#include "patient.cpp"
#include "doctor.h"
#include "doctor.cpp"
#include "diagnosis.h"
#include "diagnosis.cpp"
#include "treatmentPlan.h"
#include "treatmentPlan.cpp"
#include "nurse.h"
#include "nurse.cpp"
#include "hospital.h"
#include "hospital.cpp"

using namespace std;

int main(){

    Address add1("ul. Nowy Świat", "1", "00-001", "Warsaw", "Poland");
    Address add2("ul. Marszałkowska", "100", "00-228", "Warsaw", "Poland");
    Address add3("ul. Aleje Jerozolimskie", "120", "00-061", "Warsaw", "Poland");
    Address add4("ul. Krakowskie Przedmieście", "66/68", "00-001", "Warsaw", "Poland");
    Address add5("ul. Wilcza", "10", "00-228", "Warsaw", "Poland");

    Person person1("John Smith", "Male", 2000, "A+", add1, "+48 123456789", "123-45-6789");
    Person person2("Emily Johnson", "Female", 1990, "B-", add5, "+48 987654321", "456-432-789");
    Person person3("Michael Brown", "Male", 1982, "O+", add1, "+48 555555555", "555-55-5555");
    Person person4("Olivia Davis", "Female", 1995, "AB+", add3, " +48 111111111", "111-11-1111");
    Person person5("William Wilson", "Male", 1988, "A-", add2, "+48 999999999", "999-99-9999");
    Person person6("Sophia Taylor", "Female", 1992, "B+", add4, " +48 777777777", "777-77-7777");
    Person person7("James Anderson", "Male", 1980, "O-", add3, "+48 222222222", "222-22-2222");
    Person person8("Ava Martinez", "Female", 1993, "AB-", add5, "+48 888888888", " 888-88-8888");
    Person person9("Benjamin Thompson", "Female", 1991, "B+", add2, "+48 444444444", "444-44-4444");
    Person person10("Mia Clark", "Female", 1985, "A+", add1, "+48 666666666", "666-66-6666");
    Person person11("Jessica Pearson", "Female", 1969, "0+", add4, "+48 452789652", "452-789-652");
    Person person12("Mike Ross", "Male", 1990, "O-", add5, "+48 231457896", "231-457-896");
    Person person13("Louis Litt", "Male", 1986, "O+", add5, "+48 131127896", "131-127-896");
    Person person14("Robert Zane", "Male", 1980, "O+", add1, "+48 321457869", "321-457-869");
    Person person15("Harvey Specter", "Male", 1985, "O+", add1, "+48 661455870", "661-455-870");
    Person person16("Donna Paulsen", "Female", 1990, "O-", add3, "+48 444457896", "444-457-896");
    Person person17("Rachel Zane", "Female", 1995, "B+", add4, "+48 222275467", " 222-275-467");
    Person person18("Stu Gretchen", "Male", 1998, "O-", add5, "+48 131451196", "131-451-196");
    Person person19("Nathan Cronwell", "Male", 1999, "O-", add2, "+48 231333396", "231-333-396");
    Person person20("Tara Palmer", "Female", 2022, "B+", add2, "+48 451457896", "451-457-896");
    Person person21("Benjamin Carl", "Male", 2013, "A+", add4, "+48 236557896", "236-557-896");
    Person person22("Katarina Slim", "Female", 2020, "AB+", add1, "+48 781457656", "781-457-656");
    Person person23("Jine Gibbs", "Male", 1991, "AB+", add2, "+48 908457800", "908-457-800");

    Doctor doctor1(person12, "Generalist", 8);
    Doctor doctor2(person1, "Cardiology", 15);
    Doctor doctor3(person4, "Pediatrics", 10);
    Doctor doctor4(person8, " Oncology", 12);
    Doctor doctor5(person3, "Generalist", 10);
    Doctor doctor6(person7, "Dermatology", 8);
    Doctor doctor7(person10, "Psychiatry", 6);
    Doctor doctor8(person13, "Obstetrics and Gynecology", 18);
    Doctor doctor9(person5, "General Surgery", 13);
    Doctor doctor10(person11, "Ophthalmology", 11);
    Doctor doctor11(person6, "Receptionnist", 4); 

    Nurse nurse1(person23, 5);
    Nurse nurse2(person19, 1);
    Nurse nurse3(person18, 9);
    Nurse nurse4(person17, 15);

    vector<char*> symptoms;
    vector<char*> allergies;
    symptoms.push_back(strdup("Headache"));
    symptoms.push_back(strdup("Fever"));
    symptoms.push_back(strdup("Cough"));
    Patient patient1(person2,symptoms,allergies);

    symptoms.clear();
    allergies.clear();

    symptoms.push_back(strdup("Runny nose")); /**common cold symptoms*/
    symptoms.push_back(strdup("Sneezing")); /*no test**/
    symptoms.push_back(strdup("Cough"));
    symptoms.push_back(strdup("Loss of appetite"));
    symptoms.push_back(strdup("Headache"));
    Patient patient2(person6,symptoms,allergies);

    symptoms.clear();
    allergies.clear();
    symptoms.push_back(strdup("Runny nose")); /**influenza symptoms*/
    symptoms.push_back(strdup("Tiredness")); /*no test**/
    symptoms.push_back(strdup("Dry cough"));
    symptoms.push_back(strdup("Loss of appetite"));
    symptoms.push_back(strdup("Headache"));
    Patient patient3(person9,symptoms,allergies);

    symptoms.clear();
    allergies.clear();
    symptoms.push_back(strdup("Vomiting")); /**pneumonia symptoms*/
    symptoms.push_back(strdup("Malaise/Lethargy")); /*test**/
    symptoms.push_back(strdup("Sweating"));
    symptoms.push_back(strdup("Diarrhea"));
    symptoms.push_back(strdup("Rhinorrhea"));
    Patient patient4(person14,symptoms,allergies);

    symptoms.clear();
    allergies.clear();
    symptoms.push_back(strdup("feeling very thirsty")); /**diabetes  symptoms*/
    symptoms.push_back(strdup("needing to urinate more often than usual")); /*test**/
    symptoms.push_back(strdup("blurred vision"));
    symptoms.push_back(strdup("feeling tired"));
    symptoms.push_back(strdup("losing weight unintentionally"));
    Patient patient5(person20,symptoms,allergies);

    symptoms.clear();
    allergies.clear();
    symptoms.push_back(strdup("Pain in the neck, jaw, throat, upper abdomen or back")); /**Heart Disease  symptoms*/
    symptoms.push_back(strdup("Pain, numbness, weakness or coldness in your legs ")); /*test**/
    symptoms.push_back(strdup("Fluttering in the chest"));
    symptoms.push_back(strdup("Lightheadedness"));
    symptoms.push_back(strdup("Syncope"));
    Patient patient6(person21,symptoms,allergies);

    symptoms.clear();
    allergies.clear();
    symptoms.push_back(strdup("Pain when urinating, Blood in the urine")); /**Cancer Disease  symptoms*/
    symptoms.push_back(strdup("Pain after eating, Belly pain ")); /*test**/
    symptoms.push_back(strdup("Nausea and vomiting"));
    symptoms.push_back(strdup("Vision changes, Hearing changes"));
    symptoms.push_back(strdup("Fatigue"));
    Patient patient7(person1,symptoms,allergies); /**This person is a doctor but any person whatever its works can be a patient*/

    symptoms.clear();
    allergies.clear();
    symptoms.push_back(strdup("Emotionnal troubles")); /**Depression symptoms*/
    symptoms.push_back(strdup("Insomnia")); /*no test**/
    symptoms.push_back(strdup("Suicidal thoughts"));
    symptoms.push_back(strdup("Loss of interest in activities"));
    symptoms.push_back(strdup("Digestive problems"));
    Patient patient8(person4,symptoms,allergies);



    Hospital h1("HospiCare", add2, "+48 456 500 781");
    h1.add_doctor("dr7170MR", &doctor1, 125000, Date(11,02, 2020));
    h1.add_doctor("dr1234JS", &doctor2, 250000, Date(06,12,2021));
    h1.add_doctor("dr8756OD", &doctor3, 125000, Date(19, 04,2019));
    h1.add_doctor("dr2345JA", &doctor6, 350000, Date(12,01,2023));
    h1.add_doctor("drST-rec", &doctor11, 100000, Date(21,01,2023));

    h1.add_nurse("ns15", &nurse1, 90000, Date(01, 10, 2021));
    h1.add_nurse("ns32", &nurse2, 92000, Date(05,12,2021));

    h1.add_patient("pat1012", &patient1, "dr7170MR"); // dr7170MR is the doctorID who take care of the patient
    h1.add_patient("pat543", &patient2, "dr7170MR");
    h1.add_patient("pat3456", &patient3, "dr7170MR");
    h1.add_patient("pat8765", &patient4, "dr1234JS");
    h1.add_patient("pat1234", &patient5, "dr7170MR");
    h1.add_patient("pat7651", &patient6, "dr1234JS");
    h1.add_patient("pat8765", &patient4, "dr1234JS"); //duplicated patient


    Hospital h2("MedCare", add1, "+48 123 675 342");
    h2.add_doctor("doc600WW", &doctor9, 25000, Date(11, 05, 2023));
    h2.add_doctor("doc123JP", &doctor10, 12500, Date(03,10,2022));
    h2.add_doctor("doc546MB", &doctor5, 35000, Date(15,10,2019));
    h2.add_doctor("doc526MR", &doctor1, 35000, Date(12,11,2018));
    h2.add_doctor("doc526MR", &doctor1, 35000, Date(12,04,2022)); //duplicated doctor
    h2.add_doctor("drST-rec", &doctor11, 22000, Date(03,11,2022)); 


    h2.add_nurse("nr43", &nurse4, 92000, Date(15,02,2020));
    h2.add_nurse("nr12", &nurse3, 90000, Date(01, 10, 2023));

    h2.add_patient("p232", &patient5, "doc600WW");
    h2.add_patient("p123", &patient7, "dr7170MR"); // this doctor dr7170MR does not exit in this hospital doctor list
    h2.add_patient("p231", &patient2, "doc546MB");
    h2.add_patient("p645", &patient8, "doc546MB");
    h2.add_patient("p981", &patient6, "doc526MR");

    std::cout<<endl;

    std::cout<<"<-----------------------------------------------------------HOSPITAL STAFF MANAGEMENT----------------------------------------------> "<<endl;
    //cout<<h1;
    h1.print_doctor_patients_list("dr7170MR"); 
    h2.print_doctor_patients_list("doc546MR"); // the same person (doctor) with different id
    h1.printDoctor();
    std::cout<<"*******************************************************************************************"<<endl;
    bool result = h2.remove_DeadPatient("p231");
    if (result) {
        std::cout << "Patient p231 successfully removed" << endl;
    } else {
        std::cout << "Patient p231 not found" << endl;
    }
    std::cout<<"*******************************************************************************************"<<endl;
    h2.printPatient();

    h1.search_nurse("ns15");
    std::cout<<"*******************************************************************************************"<<endl;
    h1.set_patient_examination("pat8765", "dr1234JS", 120, 70, 9, 32);

    vector<char*>tests;  //laboratory tests 
    vector<char*>results;
    tests.push_back(strdup("Chest X-ray"));
    tests.push_back(strdup("Blood tests"));
    tests.push_back(strdup("Sputum culture"));
    tests.push_back(strdup("Pulse oximetry"));
    tests.push_back(strdup("Arterial blood gas (ABG) test"));
    tests.push_back(strdup("Bronchoscopy"));
    tests.push_back(strdup("Urine antigen test"));

    results.push_back(strdup("pneumonia")); // tests result, the patient has a pneumonia
    h1.add_patient_diagnostic("pat8765", "dr1234JS", tests, results);

    vector<char*>descriptions; // treatment plan
    descriptions.push_back("Amoxicillin - 500mg, 3 times a day, 7 days");
    descriptions.push_back("Azithromycin - 250mg, once a day, 5 days");
    descriptions.push_back("Levofloxacin - 750mg, once a day, 10 days");

    h1.add_patient_treatmentPlan("pat8765", "dr1234JS", "Medication", descriptions, Date(11, 06, 2023));

    h1.getExamination("pat8765");
    h1.getPrescription("pat8765");

    std::cout<<"*******************************************************************************************"<<endl;
    std::cout<<"Doctor hospital"<<endl;
    doctor10.getHospitalInfo();
    std::cout<<"************************************************"<<endl;
    doctor10.changeHospital(&h1);
    h1.setDoctor_info("dr777JP", 34000,Date(14,06,2023),&doctor10);
    doctor10.getHospitalInfo();
    std::cout<<"************************************************"<<endl;
    h1.printDoctor();
    return 0;
}
