#include "../../precompiled.h"
#include "../Library.h"

#include "../ByteCode.h"
#include "../CompilerUtils.h"
#include "../Scope.h"
#include "../LibraryHelper.h"

using namespace ZScript;
using namespace ZScript::Libraries;

Libraries::Global const& Libraries::Global::singleton()
{
	static Libraries::Global const instance;
	return instance;
}

const int radsperdeg = 572958;

void Global::addTo(Scope& scope) const
{
	TypeStore& typeStore = scope.getTypeStore();
	DataType tVoid = typeStore.getVoid();
	DataType tBool = typeStore.getBool();
	DataType tFloat = typeStore.getFloat();
	DataType tGame = typeStore.getGame();
	DataType tDebug = typeStore.getDebug();
	DataType tScreen = typeStore.getScreen();
	DataType tAudio = typeStore.getAudio();
	DataType tLink = typeStore.getLink();
	DataType tItemClass = typeStore.getItemClass();
	DataType tItem = typeStore.getItem();
	DataType tNpcClass = typeStore.getNpcClass();
	DataType tNpc = typeStore.getNpc();
	DataType tFfc = typeStore.getFfc();
	DataType tLWpn = typeStore.getLWpn();
	DataType tEWpn = typeStore.getEWpn();
	typedef VectorBuilder<DataType> P;

	LibraryHelper lh(scope, NUL);
	
    // int Rand(int maxval)
    {
	    Function& function = lh.addFunction(tFloat, "Rand", P() << tFloat);
	    int label = function.getLabel();
        vector<Opcode *> code;
        //pop maxval
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new ORandRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
    
    // void Quit()
    {
	    Function& function = lh.addFunction(tVoid, "Quit", P());
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OQuit());
        function.giveCode(code);
    }
    
    // void Waitframe()
    {
	    Function& function = lh.addFunction(tVoid, "Waitframe", P());
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OWaitframe();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
    
    // void Waitdraw()
    {
	    Function& function = lh.addFunction(tVoid, "Waitdraw", P());
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OWaitdraw();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void Trace(int val)
    {
	    Function& function = lh.addFunction(tVoid, "Trace", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OTraceRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void TraceB(bool val)
    {
	    Function& function = lh.addFunction(tVoid, "TraceB", P() << tBool);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OTrace2Register(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void TraceS(bool val)
    {
	    Function& function = lh.addFunction(tVoid, "TraceS", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(INDEX));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OTrace6Register(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void TraceNL()
    {
	    Function& function = lh.addFunction(tVoid, "TraceNL", P());
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OTrace3();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void ClearTrace()
    {
	    Function& function = lh.addFunction(tVoid, "ClearTrace", P());
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OTrace4();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void TraceToBase(float, float, float)
    {
	    Function& function = lh.addFunction(
			    tVoid, "TraceToBase", P() << tFloat << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OTrace5Register();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Sin(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Sin", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OSinRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int RadianSin(int val)
    {
	    Function& function = lh.addFunction(
			    tFloat, "RadianSin", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OMultImmediate(new VarArgument(EXP2), new LiteralArgument(radsperdeg)));
        code.push_back(new OSinRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int ArcSin(int val)
    {
	    Function& function = lh.addFunction(tFloat, "ArcSin", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArcSinRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Cos(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Cos", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OCosRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int RadianCos(int val)
    {
	    Function& function = lh.addFunction(
			    tFloat, "RadianCos", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OMultImmediate(new VarArgument(EXP2), new LiteralArgument(radsperdeg)));
        code.push_back(new OCosRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int ArcCos(int val)
    {
	    Function& function = lh.addFunction(tFloat, "ArcCos", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArcCosRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Tan(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Tan", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OTanRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int ArcTan(int X, int Y)
    {
	    Function& function = lh.addFunction(
			    tFloat, "ArcTan", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(INDEX2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(INDEX)));
        code.push_back(new OATanRegister(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int RadianTan(int val)
    {
	    Function& function = lh.addFunction(
			    tFloat, "RadianTan", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OMultImmediate(new VarArgument(EXP2), new LiteralArgument(radsperdeg)));
        code.push_back(new OTanRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Max(int first, int second)
    {
	    Function& function = lh.addFunction(
			    tFloat, "Max", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OMaxRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Min(int first, int second)
    {
	    Function& function = lh.addFunction(
			    tFloat, "Min", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OMinRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Pow(int first, int second)
    {
	    Function& function = lh.addFunction(
			    tFloat, "Pow", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OPowRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int InvPow(int first, int second)
    {
	    Function& function = lh.addFunction(
			    tFloat, "InvPow", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OInvPowRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Factorial(int val)
    {
	    Function& function = lh.addFunction(
			    tFloat, "Factorial", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OFactorial(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Abs(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Abs", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OAbsRegister(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Log10(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Log10", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OLog10Register(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Ln(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Ln", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OLogERegister(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int Sqrt(int val)
    {
	    Function& function = lh.addFunction(tFloat, "Sqrt", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OSqrtRegister(new VarArgument(EXP1), new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
    
    
    // void CopyTile(int source, int dest)
    {
	    Function& function = lh.addFunction(
			    tVoid, "CopyTile", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OCopyTileRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void SwapTile(int first, int second)
    {
	    Function& function = lh.addFunction(
			    tVoid, "SwapTile", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OSwapTileRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
    
    // void OverlayTile(int first, int second)
    {
	    Function& function = lh.addFunction(
			    tVoid, "OverlayTile", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OOverlayTileRegister(new VarArgument(EXP1), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
    
    // void ClearTile(int tile)
    {
	    Function& function = lh.addFunction(
			    tVoid, "ClearTile", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OClearTileRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int GetGlobalRAM(int)
    {
	    Function& function = lh.addFunction(
			    tFloat, "GetGlobalRAM", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        //pop off the params
        Opcode *first = new OPopRegister(new VarArgument(INDEX));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OSetRegister(new VarArgument(EXP1), new VarArgument(GLOBALRAMD)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void SetGlobalRAM(int, int)
    {
	    Function& function = lh.addFunction(
			    tVoid, "SetGlobalRAM", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        //pop off the params
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(INDEX)));
        code.push_back(new OSetRegister(new VarArgument(GLOBALRAMD), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int GetScriptRAM(int)
    {
	    Function& function = lh.addFunction(
			    tFloat, "GetScriptRAM", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        //pop off the params
        Opcode *first = new OPopRegister(new VarArgument(INDEX));
        first->setLabel(label);
        code.push_back(first);
        //code.push_back(new OPopRegister(new VarArgument(EXP1)));
        code.push_back(new OSetRegister(new VarArgument(EXP1), new VarArgument(SCRIPTRAMD)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void SetScriptRAM(int, int)
    {
	    Function& function = lh.addFunction(
			    tVoid, "SetScriptRAM", P() << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        //pop off the params
        Opcode *first = new OPopRegister(new VarArgument(EXP2));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(INDEX)));
        code.push_back(new OSetRegister(new VarArgument(SCRIPTRAMD), new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void SetColorBuffer(int amount, int offset, int stride, int* ptr)
    {
	    Function& function = lh.addFunction(
			    tVoid, "SetColorBuffer",
			    P() << 			    tFloat << tFloat << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OSetColorBufferRegister();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void SetDepthBuffer(int amount, int offset, int stride, int* ptr)
    {
	    Function& function = lh.addFunction(
			    tVoid, "SetDepthBuffer",
			    P() << 			    tFloat << tFloat << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OSetDepthBufferRegister();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void GetColorBuffer(int amount, int offset, int stride, int* ptr)
    {
	    Function& function = lh.addFunction(
			    tVoid, "GetColorBuffer",
			    P() << 			    tFloat << tFloat << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OGetColorBufferRegister();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // void GetDepthBuffer(int amount, int offset, int stride, int* ptr)
    {
	    Function& function = lh.addFunction(
			    tVoid, "GetDepthBuffer",
			    P() << 			    tFloat << tFloat << tFloat << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OGetDepthBufferRegister();
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int SizeOfArray(int val)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArray", P() << tFloat);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySize(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int SizeOfArrayFFC(ffc* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayFFC", P() << tFfc);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeF(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
    
    //int SizeOfArrayNPC(npc* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayNPC", P() << tNpc);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeN(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    } 
    
    // int SizeOfArrayBool(bool* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayBool", P() << tBool);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeB(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int SizeOfArrayItem(item* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayItem", P() << tItem);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeI(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int SizeOfArrayItemdata(itemdata* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayItemdata", P() << tItemClass);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeID(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int SizeOfArrayLWeapon(lweapon* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayLWeapon", P() << tLWpn);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeL(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }

    // int SizeOfArrayEWeapon(eweapon* ptr)
    {
	    Function& function = lh.addFunction(
			    tFloat, "SizeOfArrayEWeapon", P() << tEWpn);
        int label = function.getLabel();
        vector<Opcode *> code;
        Opcode *first = new OPopRegister(new VarArgument(EXP1));
        first->setLabel(label);
        code.push_back(first);
        code.push_back(new OArraySizeE(new VarArgument(EXP1)));
        code.push_back(new OPopRegister(new VarArgument(EXP2)));
        code.push_back(new OGotoRegister(new VarArgument(EXP2)));
        function.giveCode(code);
    }
	
}

