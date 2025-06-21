#pragma once

class ServeurWeb;
class Program {
 public:
  Program();
  void loop();
  
 private:
   void connexionReseau();
   ServeurWeb* m_serveurWeb;
};