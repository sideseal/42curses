"use strict";const m_root=self.location.pathname.split("/").slice(0,-1).join("/");importScripts(m_root+"/r2.js");var howManyBytes,nbCols,configurationDone=!1;function hexPairToASCII(o){o=parseInt(o,16);return 33<=o&&o<=126?String.fromCharCode(o):"."}function getChunk(e,i,r){return i<0?{offset:0,hex:[],ascii:[],flags:[],modified:[]}:(r2.cmd("p8 "+e+" @"+i,function(o){f={offset:i,hex:[],ascii:[],flags:[],modified:[]};for(var s=[],a="",n=0;n<e;n++){var t=o[2*n]+o[2*n+1];s.push(t),a+=hexPairToASCII(t),n%r==r-1&&(f.hex.push(s),f.ascii.push(a),s=[],a="")}}),r2.cmdj("fij "+i+" "+(i+e),function(o){for(var s in f.flags=o,f.flags)f.flags[s].size=parseInt(f.flags[s].size)}),f);var f}self.onmessage=function(o){var s;!configurationDone||o.data.reset?(howManyBytes=o.data.howManyBytes,nbCols=o.data.nbCols,configurationDone=!0):((s=getChunk(howManyBytes,o.data.offset,nbCols)).dir=o.data.dir,self.postMessage(s))};