%%
%Partie 1 - Algorithme de descente de gradient
clear variables;close all;

n=7;


x = -2:0.1:2;
y = x;

for k=0:n
   x_k=floor(10*rand(n,1));
end

f = @(x)((x'*x));
df = @(x)(2*x);

grad = df(x_k);
lambda =0.4;
epsilon = 10^-4;

figure(1)
hold on; 
if length(x_k) == 1
    plot(x,x.^2,'--');
elseif length(x_k) == 2
    [X,Y] = meshgrid(x,y);
    Z=X.^2+Y.^2;
    mesh(X,Y,Z);
    view(-30,60);
    grid on;
end
    
fcost = f(x_k);
i = 0;
while epsilon < norm(grad)
    i=i+1;
    x_k = x_k - lambda * df(x_k);
    grad = 2*x_k;
    
    if length(x_k) == 1
        stem(x_k,f(x_k),'r');
    elseif length(x_k) == 2
        plot3(x_k(1),x_k(2),f(x_k), 'ro');
        x_k(1);
        x_k(2);
    else
        fcost = [fcost,f(x_k)];
    end
end

if length(x_k) > 2
    plot(fcost,'r-o')
end
disp(i);
disp(x_k);
%%
%Partie 2 - Descente de gradient pour la résolution de PB d'optimisation
%lisses
clear variables;close all;  %Début de programme
addpath('matrices/')        %Ajout des dossier
addpath('operators/')       %Ajout des dossier

x = linspace(-5,5,100)';    %Vecteur x (abscisse)
x_bar = sin(x);             %Signal véritée terrain
H_floue=matH(size(x_bar),'gaussian',3); %Noyaux de floue
n = 0.1*randn(size(x_bar)); %Bruit normal

z = H_floue * x_bar + n;    %Signal Observé

figure(2);hold on;          %Affichage du signal observé et du réel
plot(x,x_bar,'r','Linewidth',3)
plot(x,z,'b')

%CORRECTION AU SENS DES MOINDRES CARREE
x_corrigee = (H_floue'*H_floue)\(H_floue'*(z)); %Correction du signal observé au sens des moindre carrée
plot(x,x_corrigee,'g','Linewidth',1)    %Affichage

%CORRECTION AVEC LA DESCENTE DE GRADIENT
g = @(x)(z);
dg = @(x)(2.*H_floue'*(H_floue*x-z));

grad = dg(x_bar);   %Initialisation (pour la boucle for)
lambda = 0.4;       %Paramétrisation du lambda ( Pas)
epsilon = 10^-4;    %Précision    
gcost = g(x_bar);   %Fonction de couts
i = 0;
x_chapeau = randn(size(x_bar));

while epsilon < norm(grad)
    i=i+1;
    x_chapeau = x_chapeau - lambda * dg(x_chapeau);
    grad = dg(x_chapeau);    
    gcost = [gcost,g(x_bar)];
end

plot(x,x_chapeau,'r--')

%2.2 Résolution du modèle de Tikhonov 1D

Gamma = matGamma(size(x),'Laplacian');
lam = 0.1356;

l = @(x)(z);
dl = @(x)(2.*H_floue'*(H_floue*x-z)+lam*(2*Gamma')*Gamma*x);

grad = dl(x_bar);   %Initialisation (pour la boucle for)
lambda = 0.4;       %Paramétrisation du lambda ( Pas)
lcost = l(x_bar);   %Fonction de couts
i = 0;
x_chapeau = z;

while epsilon < norm(grad)
    i=i+1;
    x_chapeau = x_chapeau - lambda * dl(x_chapeau);
    grad = dl(x_chapeau);    
    lcost = [lcost,l(x_bar)];
end

plot(x,x_chapeau,'c-')

%CORRECTION AU SENS DES MOINDRES CARREE (Formule de Tikhonov)
x_corrigee_tik = (((H_floue'*H_floue)+((lam*Gamma')*Gamma))\(H_floue*z)); %Correction du signal observé au sens des moindre carrée
plot(x,x_corrigee_tik,'m--','Linewidth',1)    %Affichage
legend("x bar(vérité terrain)","z (observation)","Moindre Carrée (Équation Normal sans régul)","Descente de Gradient (sans régul)","Descente de Gradient (AVEC régul)","Moindre Carrée (Équation Normal AVEC régul)")



%2.3 Résolution du modèle de Tikhonov 2D

Img = im2double(imread('cameraman.tif'));

x_bar = Img;
n = 0.1*randn(size(x_bar)); %Bruit normal

z = opH(x_bar, "gaussian",7) + n;    %Signal Observé

figure(3);hold on;          %Affichage du signal observé et du réel
subplot(231);imshow(Img)
subplot(232);imshow(z)

x_chapeau=randn(size(x_bar));

lam =0.05;

%l = @(x)(z);
%dl = @(x)(2.*H_floue'*(H_floue*x-z)+lam*(2*Gamma')*Gamma*x);

gradi = @(x)(z);
dgradi = @(x)(2*opHt(opH(x,"gaussian",7)-z,"gaussian",7)  +  lam*(2*opLt(opL(x))));

grad = dgradi(z);   %Initialisation (pour la boucle for)
lambda = 0.01;       %Paramétrisation du lambda ( Pas)
TowDcost = gradi(z);   %Fonction de couts
i = 0;
 
while 1e-4 < norm(grad)
    i=i+1;
    x_chapeau = x_chapeau - lambda * grad;
    grad = dgradi(x_chapeau);    
%     TowDcost = [TowDcost,gradi(x_chapeau)];
end
subplot(2,3,3);imshow(x_chapeau) 
subplot(2,3,[4,5,6]);plot(TowDcost,'r-o')
