close all;
clear variables;

c=2;    %Choix de cas (Image 1 = 1 | Image 2 = 2)

switch c
    case 1
        X=[1,1,0;       %Image
           0,0,1;
           0,1,0];
        x=X(:);         %Image (vectorisée)
        A=[1,1,1,0,0,0,0,0,0;  %Matrice A
           0,0,0,1,1,1,0,0,0;
           0,0,0,0,0,0,1,1,1;
           1,0,0,0,0,0,0,0,0;
           0,1,0,1,0,0,0,0,0;
           0,0,1,0,1,0,1,0,0;
           0,0,0,0,0,1,0,1,0;
           0,0,0,0,0,0,0,0,1;
           0,0,1,0,0,0,0,0,0;
           0,1,0,0,0,1,0,0,0;
           1,0,0,0,1,0,0,0,1;
           0,0,0,1,0,0,0,1,0;
           0,0,0,0,0,0,1,0,0;
           1,0,0,1,0,0,1,0,0;
           0,1,0,0,1,0,0,1,0;
           0,0,1,0,0,1,0,0,1];
       
    case 2
        X=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0; %Image
           0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
           0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
           0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
           0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0;
           0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0;
           0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0;
           0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0;
           0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0;
           0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0;
           0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0;
           0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
        x=X(:);                         %Image (vectorisée)
        A = find_projection_matrix(length(X));  %Matrice A
end

b = A*x;                    %Projection dans 16 directions de l'image
db = 0.01*(0.5-rand(size(b))); %Légère variation
tA = size(A);               %Nb de ligne/Nb de colonne

%Moindre carrée
x_mc = A\(b+db); 
X_mc = reshape(x_mc,size(X));

rank = rank(A);
[U,S,V] = svd(A);
U=U(:,1:rank);
S=S(1:rank,1:rank);
V=V(:,1:rank);

s=diag(S);

for k=1:2
   if k == 1
       lambda = 10^(-4);
       figure('Name','lambda = 10^(-4)');
       
   else 
       lambda = 10^(-6);
       figure('Name','lambda = 10^(-6)');
   end
   
   %Régularisation de Tikhonov VERSION 1
   x_tik = (A'*A + lambda*eye(tA(2)))\(A'*b);
   X_tik = reshape(x_tik,size(X));
   
   %Régularisation de Tikhonov VERSION 2
   Diag = S ./ (S.^2 + lambda);
   x_tik2 = V * Diag * U'*b;
   
   X_tik2 = reshape(x_tik2,size(X));
           
   %Affichage :
   subplot(2,4,1);imshow(X);title('Image Original')
   subplot(2,4,2);imshow(X_mc);title('X moindres carres')
   subplot(2,4,3);imshow(X_tik);title('X de Tikhonov V1')
   subplot(2,4,4);imshow(X_tik2);title('X de Tikhonov V2')

   subplot(2,4,[5,6,7,8]);plot(diag(S));

   cond = max(diag(S))/min(diag(S));
      
end






