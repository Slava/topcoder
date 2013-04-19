// imslavko
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define all(c) c.begin(),c.end() 

int g[50][50], n, u[50];
vector<int> cities, sum;

class GreedyTravelingSalesman {
	public:
	int go() {
		memset(u, 0, sizeof u);
		int visited = 1, cur = 0, len = 0;
		while (visited < n) {
			u[cur] = 1;
			visited++;
			int v = -1;
			for (int i = 0; i < n; i++)
			   if (!u[i] && (v == -1 || g[cur][i] < g[cur][v]))
			   	v = i;
	 		len += g[cur][v];
			cur = v;
		}
		return len;
	}
	int worstDistance(vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones) {
		n = (int)thousands.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = (thousands[i][j]-'0') * 1000 + (hundreds[i][j]-'0') * 100 + (tens[i][j]-'0') * 10 + ones[i][j]-'0';

		int visited = 1, cur = 0, len = 0;
		while (visited < n) {
			cities.pb(cur);
			sum.pb(len);
			u[cur] = 1;
			visited++;
			int v = -1;
			for (int i = 0; i < n; i++)
			   if (!u[i] && (v == -1 || g[cur][i] < g[cur][v]))
			   	v = i;
	 		len += g[cur][v];
			cur = v;
		}

		cities.pb(cur);
		sum.pb(len);

		int res = 0;
		for (int i = 1; i < n; i++) {
			int pr = cities[i-1];
			int cu = cities[i];
			int ll = g[pr][cu];
			for (int j = 1; j < 10000; j++) {
				g[pr][cu] = j;
				res = max(res, go());
			}
			g[pr][cu] = ll;
			for (int j = 0; j < n; j++) {
				int lll = g[pr][j];
				g[pr][j] = ll;
				res = max(res, go());
				g[pr][j] = lll;
			}
			for (int j = 0; j < n; j++) {
				int lll = g[pr][j];
				if (ll-1 < 1)continue;
				g[pr][j] = ll-1;
				res = max(res, go());
				g[pr][j] = lll;
			}
		}

		return res;
	}
};
 
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing GreedyTravelingSalesman (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338654024;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GreedyTravelingSalesman _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string thousands[] = {"055", "505", "550"};
				string hundreds[] = {"000", "000", "000"};
				string tens[] = {"000", "000", "000"};
				string ones[] = {"000", "000", "000"};
				_expected = 14999;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 1:
			{
				string thousands[] = {"018", "101", "990"};
				string hundreds[] = {"000", "000", "990"};
				string tens[] = {"000", "000", "990"};
				string ones[] = {"000", "000", "990"};
				_expected = 17999;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 2:
			{
				string thousands[] = {"00888", "00999", "00099", "00009", "00000"};
				string hundreds[] = {"00000", "00999", "00099", "00009", "00000"};
				string tens[] = {"00000", "10999", "11099", "11109", "11110"};
				string ones[] = {"01000", "00999", "00099", "00009", "00000"};
				_expected = 37997;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 3:
			{
				string thousands[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
				string hundreds[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
				string tens[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
				string ones[] = {"011111", "101111", "990998", "999099", "999809", "999980"};
				_expected = 39994;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 4:
			{
				string thousands[] = {"00", "00"};
				string hundreds[] = {"00", "00"};
				string tens[] = {"00", "00"};
				string ones[] = {"01", "10"};
				_expected = 9999;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 5:
			{
				string thousands[] = {"0930", "1064", "0104", "1070"};
				string hundreds[] = {"0523", "1062", "6305", "0810"};
				string tens[] = {"0913", "0087", "3109", "1500"};
				string ones[] = {"0988", "2030", "6103", "5530"};
				_expected = 14124;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 6:
			{
				string thousands[] = {"0329", "2036", "2502", "8970"};
				string hundreds[] = {"0860", "5007", "0404", "2770"};
				string tens[] = {"0111", "2087", "2009", "2670"};
				string ones[] = {"0644", "1094", "7703", "7550"};
				_expected = 17785;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 7:
			{
				string thousands[] = {"098444156277392825243100607342", "200097656837707947798866622385",
				                     "290231695687128834848596019656", "407026565077650435591867333275",
				                     "843401002617957470339040852874", "349970591997218853400632158696",
				                     "419933000593511123878416328483", "696294503254214847884399055978",
				                     "641473980706392541888675375279", "936720077098054565078142449625",
				                     "203476089500970673371115103717", "511071853860312304204656816567",
				                     "347105714685052402147763392257", "125122220860203856679947732062",
				                     "121462979669220132944063071653", "928254504048223043681383050365",
				                     "502607124708785202536036594373", "793596587517012870906900400361",
				                     "712360060935346182084840996318", "761671392040312345002273366240",
				                     "812935320276738878200716148806", "228506917464479046839069740872",
				                     "755395721473881083093906155745", "192597782177910118061710039501",
				                     "721382839206745793530453013267", "076061794267810491768114700256",
				                     "857528357758085424372388710251", "173322450800442594145600093043",
				                     "761667192345925280210514410800", "521229810525064090301842864060"};
				string hundreds[] = {"098270581534726237580246464451", "108829763716747148395013332067",
				                    "830061279541380758964430491222", "431005058477371114834129826284",
				                    "601807314489142917339949914290", "330640126699733151822328009407",
				                    "851821069798846354566780680271", "648888407535627630663351884365",
				                    "051398660825518466890170447894", "631934884097214069747147155777",
				                    "768071219404930950472885304916", "924954163330715847561718395488",
				                    "189910033179029204426829479070", "960645776060701332402794474433",
				                    "244875842263950931884758650019", "528470075229660077692189442311",
				                    "752198673046476808978058423064", "899325998610605600525587569431",
				                    "965750123741820904031880230236", "121658852172052167706008445728",
				                    "556199378085507717770434101126", "864838242791403197110088834005",
				                    "593435343245223500439707230479", "622529771475840345624500421425",
				                    "503486612623475041392122088159", "518334626169655694269507400008",
				                    "967091631529233593414345370288", "300474162107271438029222620086",
				                    "010527691044447729596127150108", "742822904991333205419603623270"};
				string tens[] = {"029421809872798033258029765788", "705135039569772524273274786652",
				                "170567418260893393020344098265", "401043354947659563658581268242",
				                "746709065616595245635350557925", "739570024549618413776557843034",
				                "184597012262496958610853505745", "689811400727818703807051112784", 
				                "894453010121164288965541305235", "323145029073008946088869964941", 
				                "834269564400729646453274750586", "538976762970745472202055589093", 
				                "765511399939087047106252621388", "906733295711605356366138410423", 
				                "107653940551700559321642810836", "428402693021051075533830345295", 
				                "386782660475155103347385287948", "936626025836194580089064628716", 
				                "718522629491464055045890912121", "370656945845300237607868352243", 
				                "951908186614186444840337711498", "535178875249889835014025850038", 
				                "505970047705717604298603983975", "484398304612602344941130624527", 
				                "048342694079170795987835013947", "860331019262176299872846206272", 
				                "549663926438975145562538360932", "329735455392841851511474791078", 
				                "711755200061373546828858448100", "778808866574640894148527759780"};
				string ones[] = {"050738147930236727719964251439", "804492562859282318664226330103", 
				                "610197568193830684654773608216", "279000416545607314567843085541", 
				                "782201171759873927350740022455", "043370803444176631019883186675", 
				                "566092086050401228622782761449", "469598907881602996036692882305", 
				                "116923500417992303845370254124", "796876115092839169954790509461", 
				                "783836410405270687557924090071", "095144151150833738671751747749", 
				                "354474585664039135189964700948", "328968176148004939648962631420", 
				                "829651915384290848347221555092", "170980383407813034573738951375", 
				                "728655435703349509419725538350", "121896684176286430427852435647", 
				                "315710894574884960021671476788", "592177839598531202003634382961", 
				                "876587919610157913350259498196", "505517243779897451333006271744", 
				                "618607877753891664471800511372", "826358757330233811836040764274", 
				                "206641252044293046424432092833", "704519364781672964993499009545", 
				                "624793571592392775564426440338", "571938479010503551295729304078", 
				                "077967252884369103891335711508", "870185204806328841827105139840"};
				_expected = 39896;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			case 8:
			{




				string thousands[] = 
				{"000", "000", "000"};
				string hundreds[] = 
				{"000", "000", "000"};
				string tens[] = 
				{"000", "000", "000"}
					;
				string ones[] = 
				{"032", "101", "120"}
					;
				_expected = 10001;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}
			/*case 9:
			{
				string thousands[] = ;
				string hundreds[] = ;
				string tens[] = ;
				string ones[] = ;
				_expected = ;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string thousands[] = ;
				string hundreds[] = ;
				string tens[] = ;
				string ones[] = ;
				_expected = ;
				_received = _obj.worstDistance(vector <string>(thousands, thousands+sizeof(thousands)/sizeof(string)), vector <string>(hundreds, hundreds+sizeof(hundreds)/sizeof(string)), vector <string>(tens, tens+sizeof(tens)/sizeof(string)), vector <string>(ones, ones+sizeof(ones)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
