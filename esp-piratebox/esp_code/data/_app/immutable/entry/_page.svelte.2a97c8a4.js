import{S as B,i as U,s as L,k as b,q as P,a as x,l as I,m as w,r as k,h,c as D,n as $,b as C,C as c,J as T,D as q,w as j,K as S,y as A,z as N,A as O,g as R,d as z,B as F}from"../chunks/index.0c4cb16c.js";function H(f){let e,a;return{c(){e=b("p"),a=P("Aucune Image")},l(t){e=I(t,"P",{});var s=w(e);a=k(s,"Aucune Image"),s.forEach(h)},m(t,s){C(t,e,s),c(e,a)},p:q,d(t){t&&h(e)}}}function V(f){let e,a;return{c(){e=b("img"),this.h()},l(t){e=I(t,"IMG",{src:!0,alt:!0}),this.h()},h(){S(e.src,a=f[0])||$(e,"src",a),$(e,"alt","d")},m(t,s){C(t,e,s)},p(t,s){s&1&&!S(e.src,a=t[0])&&$(e,"src",a)},d(t){t&&h(e)}}}function G(f){let e,a,t,s,v,p,E,i,l,u,n;function m(r,d){return r[0]?V:H}let g=m(f),o=g(f);return{c(){e=b("section"),a=b("h1"),t=P("Charger une image"),s=x(),o.c(),v=x(),p=b("input"),E=x(),i=b("button"),l=P("publier l'image"),this.h()},l(r){e=I(r,"SECTION",{class:!0});var d=w(e);a=I(d,"H1",{});var _=w(a);t=k(_,"Charger une image"),_.forEach(h),s=D(d),o.l(d),v=D(d),p=I(d,"INPUT",{type:!0}),E=D(d),i=I(d,"BUTTON",{class:!0});var y=w(i);l=k(y,"publier l'image"),y.forEach(h),d.forEach(h),this.h()},h(){$(p,"type","file"),$(i,"class","bg-red-400 rounded-xl p-4"),$(e,"class","bg-slate-700 p-5")},m(r,d){C(r,e,d),c(e,a),c(a,t),c(e,s),o.m(e,null),c(e,v),c(e,p),f[3](p),c(e,E),c(e,i),c(i,l),u||(n=T(p,"change",f[2]),u=!0)},p(r,[d]){g===(g=m(r))&&o?o.p(r,d):(o.d(1),o=g(r),o&&(o.c(),o.m(e,v)))},i:q,o:q,d(r){r&&h(e),o.d(),f[3](null),u=!1,n()}}}function J(f,e,a){let t,s;const v=i=>{console.log(i.target.files[0]);let l=i.target.files[0],u=new FileReader;u.readAsDataURL(l),u.onload=n=>{p(n.target.result)}};function p(i){const l=document.createElement("canvas"),u=l.getContext("2d"),n=new Image;n.crossOrigin="anonymous",n.src=i,n.onload=function(){let m=n.width>1e3?1e3:n.width,g=n.height*(m/n.width);l.width=m,l.height=g,u.drawImage(n,0,0,m,g);let o=u.getImageData(0,0,m,g),r=o.data;for(let _=0;_<r.length;_+=4){let y=(r[_]+r[_+1]+r[_+2])/3;r[_]=y,r[_+1]=y,r[_+2]=y}u.putImageData(o,0,0);let d=l.toDataURL("image/webp",.3);a(0,t=d)}}function E(i){j[i?"unshift":"push"](()=>{s=i,a(1,s)})}return[t,s,v,E]}class K extends B{constructor(e){super(),U(this,e,J,G,L,{})}}function M(f){let e,a,t,s,v,p,E,i,l,u;return l=new K({}),{c(){e=b("section"),a=b("div"),t=b("h2"),s=P("Bienvenue"),v=x(),p=b("p"),E=P(`Inspiré du mouvement PirateBox, ce projet a pour but de créer un réseau de partage de fichiers et d'echange de message décentralisé.
            Il est basé sur un ESP32, une petite carte électronique peux couteuse (2-3 euros environ) qui permet de créer un réseau wifi.
            Le projet est open source et librement accessible. Vous pouvez le télécharger et le modifier à votre guise.`),i=x(),A(l.$$.fragment)},l(n){e=I(n,"SECTION",{});var m=w(e);a=I(m,"DIV",{});var g=w(a);t=I(g,"H2",{});var o=w(t);s=k(o,"Bienvenue"),o.forEach(h),v=D(g),p=I(g,"P",{});var r=w(p);E=k(r,`Inspiré du mouvement PirateBox, ce projet a pour but de créer un réseau de partage de fichiers et d'echange de message décentralisé.
            Il est basé sur un ESP32, une petite carte électronique peux couteuse (2-3 euros environ) qui permet de créer un réseau wifi.
            Le projet est open source et librement accessible. Vous pouvez le télécharger et le modifier à votre guise.`),r.forEach(h),g.forEach(h),i=D(m),N(l.$$.fragment,m),m.forEach(h)},m(n,m){C(n,e,m),c(e,a),c(a,t),c(t,s),c(a,v),c(a,p),c(p,E),c(e,i),O(l,e,null),u=!0},p:q,i(n){u||(R(l.$$.fragment,n),u=!0)},o(n){z(l.$$.fragment,n),u=!1},d(n){n&&h(e),F(l)}}}class Q extends B{constructor(e){super(),U(this,e,null,M,L,{})}}export{Q as default};