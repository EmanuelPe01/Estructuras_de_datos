// Incluir en el main a "ArBin.h"

typedef ArBin ArBB;

ArBB InsOrdB(Elem e, ArBB a){
   if(esvacioB(a))
       return consB(e,vacioB(),vacioB());
   else if(EsMenor(e,raiz(a)))
            return consB(raiz(a),InsOrdB(e,izquierdoB(a)),derechoB(a));
        else
            return consB(raiz(a),izquierdoB(a),InsOrdB(e,derechoB(a)));
}
