#pragma once

class ServeurWeb;
class LCD1602;
class Program {
 public:
  Program();
  void loop();
  
 private:
   void connexionReseau();
   ServeurWeb* m_serveurWeb;
   LCD1602* m_LCD;
};
