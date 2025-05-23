// B2DL.cpp
// Brandon Montez
// CISP 360
// 04/11/21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ProgramGreeting();
bool playOn();

class B2DL {
  public:
    B2DL() {
      m_diplomat = false,
      m_intimidator = false,
      m_dirty_chair = false,
      m_grateful_haiken = false;
    }

    void startGame() {
      cout << "\t\t\t\t\tBUTLER TO THE DARK LORD\n" << endl;
      A1();
    }

    // Specification B2 - Individual Functions
    void A1() {
      int opts = 2;  // number of options available to the user
      string path_name = "A1";
      storeKey(path_name);

      // Specification C3 - Room Header
      cout << m_tab << path_name << endl;
      cout << "\tWell, Mr Artanon, look at you. Who would have thought that\n"
              "the son of a lowly spider farmer could rise to such esteemed\n"
              "heights? Yet here you are, standing in the kitchens of Cayfax\n"
              "Castle, dressed in the finest livery onyx can buy. For you, sir,\n"
              "are butler to Malacandros, Dark Lord of all Nocturnia. The flames\n"
              "of fireplaces tickle suspended pots, which thicken the air with\n"
              "competing scents. Workers along stone benches busily chop and\n"
              "kill ingredients - nothing but the best for his lordship, of\n"
              "course. In the centre of the chamber a great oven blazes, its\n"
              "cracked chimney oozing smoke. ’Ah, Mr Artanon,’ simpers Repugnis,\n"
              "the head cook. He’s a fat goblin who samples too many of his own\n"
              "creations, as evidenced by his bulging belly and the delta of\n"
              "stains down his apron. ’I’m roasting his Horrendousness a prime\n"
              "briar beast basted in snake oil. Mmm-mmm! The intestines are\n"
              "stuffed with rotten apple and breadcrumb, and I’ve shoved a\n"
              "carrot up its arse.’ You arch an eyebrow, for Mal is already\n"
              "situated upstairs in the dining hall. With midday waning, he\n"
              "will be growing hungry. ’And just how long,’ you ask, ’do you\n"
              "intend to keep his lordship staring at an empty plate?’ Repugnis\n"
              "titters nervously, and glances towards the oven. ’Good sir, a\n"
              "roast takes as long as a roast takes. If I stoke the flames any\n"
              "hotter the skin will crisp to charcoal. At best I could aim for\n"
              "a rare cut?’\n\n\t\t\tWhat is your reply?\n" << endl;

      string opt1 = "’It’s you who’ll get a rare cut across that corpulent neck\n"
                    "of yours if you don’t speed things along, you feckless blob\n"
                    "of festering lard.’ (turn to A100)\n";
      string opt2 = "’Surely in such an industrious kitchen, there must be a\n"
                    "starter or two ready to send along and sate His\n"
                    "Abhorentness’s appetite?’ (turn to A167)\n";
      cout << "1. " << opt1 << endl;
      cout << "2. " << opt2 << endl;

      // Specification C2 - Simple menu
      if (getChoice(opts) == 1) {
        cout << opt1 << endl;
        cout << path_name << " -> A100\n" << endl;
        A100();
      }
      else {
        cout << opt2 << endl;
        cout << path_name << " -> A167\n" << endl;
        A167();
      }
    }
    
    void A167() {
      int opts = 1;
      string path_name = "A167";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tRepugnis nods eagerly, which ripples his many chins. \"Yes sir,\n"
              "of course! Let me see now...\" He glances around and spots a bench\n"
              "where several platters are being assembled. \"Ah! How about some\n"
              "pickled rat heads and delectable carpaccio of slug?\" \"Very good,\"\n"
              "you say. \"I am told that Captain Haiken is particularly partial to\n"
              "rat. But see that you hurry along now, Repugnis. I don’t need to\n"
              "remind you that his lordship’s patience is virtually non-existent\n"
              ".\" \"Of course, sir, of course.\" You click your fingers at some\n"
              "waiting footmen and they leap to action, seizing the platters and\n"
              "heading for the door.\n" << endl;

      cout << "\t\t\tIt seems you are a DIPLOMAT.\n" << endl;
      m_diplomat = true;

      string opt1 = "Onwards, Mr Artanon. (turn to A232)\n";
      cout << "1. " << opt1 << endl;
      getChoice(opts);

      cout << opt1 << endl;
      cout << path_name << " -> A232\n" << endl;
      A232();
    }

    void A100() {
      int opts = 1;
      string path_name = "A100";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tRepugnis turns a paler shade of green, and gulps. \"I beg\n"
              "you, Mr Artanon, stay your hand. I’m sure that something must\n"
              "be ready.\" The cook glances around and spots a bench at which\n"
              "several trays are being assembled. \"Ah!\" he says. \"How about\n"
              "some pickled rat heads and carpaccio of slug?\" You scowl, long\n"
              "enough to make Repugnis quiver, then turn and snap at some lurking\n"
              "footmen. \"Get those trays up to his lordship without delay!\"\n"
              "The footmen spring into action, seizing the trays and heading for\n"
              "the door. \"Thank you, sir,\" says Repugnis. \"Thecroast will\n"
              "not be far behind, I promise.\" \"See that it isn’t,\" you reply,\n"
              "\"or the next item on the menu might be goblin stew.\"\n" << endl;

      cout << "\t\t\tIt seems you are an INTIMIDATOR.\n" << endl;
      m_intimidator = true;

      string opt1 = "Onwards, Mr Artanon. (turn to A232)\n";
      cout << "1. " << opt1 << endl;
      getChoice(opts);

      cout << opt1 << endl;
      cout << path_name << " -> A232\n" << endl;
      A232();
    }

    void A232() {
      int opts = 2;
      string path_name = "A232";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tYou overtake the footmen along a corridor lit by stuttering\n"
              "candles, and lead them through a wide archway into the airy\n"
              "dining hall. Great windows stand open along one wall, looking out\n"
              "upon a pleasant view of circling lizard-birds cannibalizing their\n"
              "young. Down the length of the hall runs an immense marble table,\n"
              "at the head of which the Dark Lord Malacandros reclines in a\n"
              "chair of elaborately carved dragon bone. He is a gaunt man with\n"
              "darting eyes and sharp features, currently dressed in a very\n"
              "tasteful grey robe (which you helped him get into this morning),\n"
              "his black hair clasped in a ponytail down his back. To his right\n"
              "sits Captain Haiken, one of his favored brutes, a well muscled\n"
              "orc in polished steel. \"Ah, Mr Artanon,\" says Mal, \"I was\n"
              "beginning to worry we’d been forgotten.\" He gives you a thin\n"
              "smile, which warns you he is very close to becoming irked. You\n"
              "bow deeply. \"My humble apologies, oh Intolerant One. Repugnis is\n"
              "putting the final touches on today’s main course, and you know\n"
              "what a perfectionist he is. In the meantime,\" you whisk a\n"
              "platter from one of the footmen, \"here are some starters to whet\n"
              "your appetites.\" As you move toward the head of the table, Haiken\n"
              "licks his lips. \"Rat heads!\" he exclaims. \"My favorite.\"\n"
              "\n\t\t\tWho will you serve first?\n" << endl;

      string opt1 = "The enthusiastic Captain Haiken? (turn to A13)\n";
      string opt2 = "Or your master, Malacandros? (turn to A290)\n";
      cout << "1. " << opt1 << endl;
      cout << "2. " << opt2 << endl;

      if (getChoice(opts) == 1) {
        cout << opt1 << endl;
        cout << path_name << " -> A13\n" << endl;
        A13();
      }
      else {
        cout << opt2 << endl;
        cout << path_name << " -> A290\n" << endl;
        A290();
      }
    }
    
    void A290() {
      int opts = 1;
      string path_name = "A290";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tAs is only fitting, you serve your master first. As you\n"
              "place the largest and juiciest rat heads before him, your first\n"
              "footman Kalag - a young fellow who shows much promise - moves to\n"
              "Haiken and starts laying slug meat on his plate. \"Er,\" says\n"
              "Haiken, \"not too much slug for me, thank you - I have an\n"
              "allergy.\" Mal, who is in mid-chew, scoffs, and shoots a shard\n"
              "of half-chewed rat skull out of his nostril to ping off a wine\n"
              "glass. \"Rut me, Haiken,\" he says. \"I’ve seen you rip the\n"
              "throat from a charging horse, yet you can’t stomach a little\n" 
              "slug?\" Haiken seems embarrassed. \"They give me hives, my\n"
              "lord.\" \"Ha! Well, better get over there with some of his\n"
              "precious rat heads, Mr Artanon.\" You do as you are bid, and\n"
              "place the remaining rat heads on Haiken’s plate. They are a\n"
              "little on the smaller side, and you notice a wistful look in\n"
              "Haiken’s eye as Mal lifts another plump one to his mouth. With\n"
              "your lords served, you move back from the table to remain in\n"
              "waiting.\n" << endl;

      string opt1 = "Excellent posture, Mr Artanon. (turn to A161)\n";
      cout << "1. " << opt1 << endl;
      getChoice(opts);

      cout << opt1 << endl;
      cout << path_name << " -> A161\n" << endl;
      A161();
    }

    void A13() {
      int opts = 0;
      string path_name = "A13";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tFeeling dangerous, Mr Artanon? You move past Mal to Captain\n"
              "Haiken and, using a pair of tongs fashioned to look like crow’s\n"
              "claws, start placing rat heads onto his plate. As you do, you\n"
              "glance surreptitiously at Mal, wondering if you have irritated\n"
              "him by serving his guest first - he is not exactly known for his\n"
              "good manners - but he does not seem to have noticed. At any rate,\n"
              "your first footman, Kalag - a young man who shows much promise -\n"
              "hops to action, to lay slivers of slug meat on Mal’s plate. \n"
              "\"Er...\" says Haiken, his meaty hand skimming the tableware.\n"
              "You realize he is uncertain about what, amongst the array of\n"
              "cutlery laid out on either side of his plate, is the correct\n"
              "implement to use for rat heads.\n" << endl;

      string opt1 = "Since you are a DIPLOMAT - (turn to A212)\n";
      string opt2 = "Do you simply inform him which is the proper\n"
                    "rat-head-eating-fork? (turn to A159)\n";
      string opt3 = "Or do you let him flounder? (turn to A173)\n";

      //Specification B3 - Valid choices only
      if (m_diplomat == true) {
        opts = 1;
        cout << "1. " << opt1 << endl;
      }
      else {
        opts = 2;
        cout << "1. " << opt2 << endl;
        cout << "2. " << opt3 << endl;
      }

      if (getChoice(opts) == 1) {
        if (opts == 1) {
          cout << opt1 << endl;
          cout << path_name << " -> A212\n" << endl;
          A212();
        }
        else {
          cout << opt2 << endl;
          cout << path_name << " -> A159\n" << endl;
          A159();
        }
      }
      else {
        cout << opt3 << endl;
        cout << path_name << " -> A173\n" << endl;
        A173();
      }
    }

    void A212() {
      int opts = 1;
      string path_name = "A212";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tYou clear your throat very slightly, and Haiken glances up\n"
              "at you. As you move your hand back from his plate, you let your\n"
              "finger rest momentarily on the appropriate rat-head-eating fork.\n"
              "Haiken understands, and gives you a relieved look. Mal is too\n"
              "busy shoveling slug meat into his gullet to notice the exchange,\n"
              "so HAIKEN IS GRATEFUL. You add some rat heads to Mal’s plate and\n"
              "move back from the table to take a place in waiting.\n" << endl;

      m_grateful_haiken = true;

      string opt1 = "Nicely done, Mr Artanon. (turn to A161)\n";
      cout << "1. " << opt1 << endl;
      getChoice(opts);

      cout << opt1 << endl;
      cout << path_name << " -> A161" << endl;
      A161();
    }

    void A173() {
      int opts = 2,
          m_choice = 0;
      string path_name = "A173";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tAs they gnash away, Mal and Haiken discuss the Captain’s\n"
              "recent raid on the town of Greenflower. \"Honestly,\" says\n"
              "Haiken, \"those wretched Brightlanders are so easily\n"
              "slaughtered, sometimes I almost feel bad for them.\" Mal laughs\n"
              "at this hilarious joke. \"Ha! That’s a good one, Captain. But\n"
              "tell me, what of your primary objective?\" \"I am pleased to\n"
              "report success, my lord.\" \"You have brought me a virgin?\"\n"
              "\"She languishes in your dungeon even now - lovely, virtuous\n"
              "and ripe for sacrifice.\" \"Excellent. My skywatchers predict a\n"
              "full moon in three nights time - perfect conditions for the\n"
              "ceremony.\" Footsteps sound at the dining hall entrance, and a\n"
              "goblin messenger, whom you recognize as Peedy, enters wearing a\n"
              "feathered hat and carrying a scroll. Mal’s gaze slides to him.\n"
              "\"What is it?\" Peedy clears his throat. \"Apologies for the\n"
              "interruption, Your Atrociousness. I bring you word from Vorganis\n"
              "Castle.\" \"Oh?\" Mal’s tone is so instantly cold that the very\n"
              "temperature of the room seems to drop. \"Er... yes, my lord.\n"
              "Lord Nefarian accepts your kind invitation to attend the Stygias\n"
              "Ceremony, and intends to arrive tomorrow morning.\" Mal’s eyes\n"
              "narrow. You know he does not care for his cousin Nefarian, not\n"
              "least because the man is next in line to the throne. Nefarian’s\n"
              "presence at the ceremony, however, must be tolerated, for he is\n"
              "a powerful lord in his own right, with many allies amongst\n"
              "Nocturnia’s nobility - a fact which Mal does not enjoy being\n"
              "reminded of. \"Why bring me such news at lunch?\" he growls.\n"
              "\"It has put a foul taste in my mouth and sullied my food.\" He\n"
              "drums his fingers on the dragon bone armrest, and fiery sparks\n"
              "flare at his fingertips. Peedy quails, for he knows that Mal is\n"
              "prone to taking out his anger on the bearers of bad news. It\n"
              "would be a shame, however (and a staffing issue), to lose a\n"
              "competent messenger to a moment of ill temper over something\n"
              "that really isn’t his fault.\n" << endl;

      cout << "1. Do you attempt to intercede on Peedy’s behalf? (Done)\n" << endl;
      cout << "2. Or abandon him to his miserable fate? (Done)\n" << endl;

      if (getChoice(opts) == 1) {
        cout << "Attempt to intercede on Peedy's behalf.\n\n(Done)" << endl;
      }
      else {
        cout << "Abandon him to his miserable fate.\n\n(Done)" << endl;
      }
    }

    void A159() {
      int opts = 1;
      string path_name = "A159";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tYou clear your throat and speak softly. \"That little one\n"
              "there is your rat-head-eating-fork, my lord.\" Despite your\n"
              "attempt to be subtle, Mal registers the exchange and chortles.\n"
              "Haiken, embarrassed to be found ignorant, frowns. \"I know what\n"
              "fork to use, you stupid butler! Begone before I stab you in the\n"
              "eye with it.\" With your lords served, you move back from the\n"
              "table to remain in waiting. Somehow you doubt Haiken’s\n"
              "bedclothes will be properly turned.\n" << endl;

      cout << "1. (Done)\n" << endl;
      getChoice(opts);

      cout << "(Done)" << endl;
    }

    void A161() {
      int opts = 1;
      string path_name = "A161";
      storeKey(path_name);

      cout << m_tab << path_name << endl;
      cout << "\tYou move away from Haiken, whose hand still hovers\n"
              "uncertainly over the cutlery, to serve Mal rat heads. Finally\n"
              "Haiken makes a decision and picks up a carapace-cracking-spork.\n"
              "Mal chuckles at his ignorance. \"By Stygias, Captain - have you been\n"
              "in the field so long that you’ve forgotten the basic functions of\n"
              "tableware?\" Haiken grimaces. \"Pardon me, your Pettiness. I may\n"
              "have had a noble birth, yet life as a soldier puts me out of\n"
              "touch with certain niceties. We tend to eat with our hands.\"\n"
              "Mal laughs. \"Well, let us not stand on ceremony, Captain! I am\n"
              "happy to do it your way!\" Mal picks up a rat head with his hand\n"
              "and shovels it into his mouth. Haiken happily follows suit,\n"
              "munching and cracking skulls with his teeth. Inwardly, you give a\n"
              "sigh. No doubt with such messy fingers, Mal will stain the dragon\n"
              "bone. Why, you have often wondered, would anyone fashion a dining\n"
              "chair out of such easily blemished material as bleached porous\n"
              "bone? Just as you fear, Mal leans back to rest his grubby mitts\n"
              "upon the armrests. The CHAIR IS DIRTY. You move back to the wall\n"
              "while your lords eat, to remain in waiting. A butler’s work is\n"
              "never\n" << endl;

      m_dirty_chair = true;

      cout << "1. (Done)\n" << endl;
      getChoice(opts);

      cout << "(Done)\n" << endl;
    }

    // Specification A2 - Path
    void getPath() {
      int last = m_key.size() - 1;
      cout << "\t\t\tPath taken" << endl;
      for (int i = 0; i < last; i++){
        cout << m_key.at(i) << " -> ";
      }
      cout << m_key.at(last) << endl << endl;
    }

    // Specification B1 - Booleans
    void getStats() {
      string f = "FALSE",
             t = "TRUE";

      string dipl = f,
            inti = f,
            dirt = f,
            grat = f;

      if (m_diplomat == true) {
        dipl = t;
      }
      if (m_intimidator == true) {
        inti = t;
      }
      if (m_dirty_chair == true) {
        dirt = t;
      }
      if (m_grateful_haiken == true) {
        grat = t;
      }

      cout << "\t\t\tStatus Effects" << endl;
      cout << "Diplomat: " << dipl << endl;
      cout << "Intimidator: " << inti << endl;
      cout << "Grateful Haiken: " << grat << endl;
      cout << "Dirty Chair: " << dirt << endl;
    }

  private:
    // formatting for titles
    string m_tab = "\t\t\t\t\t\t\t ";

    // path key
    vector<string> m_key;

    // statuses
    bool m_diplomat,
         m_intimidator,
         m_dirty_chair,
         m_grateful_haiken;

    // user decision
    int m_choice;

    // Specification A1 - Input Validation
    int getChoice(int num_opts) {
      bool bad_choice;
      do {
        cout << "Please make a decision: ";
        cin >> m_choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (m_choice < 1 || num_opts < m_choice) {
          cout << "Error - invalid choice.\n" << endl;
          bad_choice = true;
        }
        else {
          bad_choice = false;
        }
      } while(bad_choice);
      cout << endl;
      return m_choice;
    }

    void storeKey(string path_name) {
      m_key.push_back(path_name);
    }
};

// Specification C1 - A function
bool playOn() {
  char inp;
  bool play;

  do {
    cout << "\nWould you like to play again? (y/n): ";
    cin >> inp;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (inp == 'y') {
      play = true;
      cout << endl;
    }
    else if (inp == 'n') {
      play = false;
    }
    else {
      cout << "Error - Invalid entry." << endl;
    }
  } while (inp != 'y' && inp != 'n');
  return play;
}

void ProgramGreeting() {
  cout << "Welcome, and good luck.\n"
          "Brandon Montez\n"
          "CISP 360\n"
          "April 11, 2021\n" << endl;
}

int main() {
  bool play;

  ProgramGreeting();

  // Specification A3 - Game loop
  do {
    B2DL game;
    game.startGame();
    game.getPath();
    game.getStats();
    play = playOn();
  } while (play);

  return 0;
}