function splane(numerator, denominator)
    z = roots(numerator);
    p = roots(denominator);
    C = [min(imag(z)) min(imag(p))];
    C = min(C) - 1;

    B1 = [max(imag(z)) max(imag(p))];
    B1 = max(B1) + 1;

    D = (abs(C) + abs(B1)) / 2;
    im = C:D:B1;
    Nq = length(im);
    re = zeros(1, Nq);

    A = [min(imag(z)) min(imag(p))];
    A = min(A) + 1;

    stem(real(z), imag(z), 'o:')
    hold on
    stem(real(p), imag(p), 'x:')
    hold on
    plot(re, im, 'k')
    xlabel('\sigma')
    ylabel('j\omega')
    grid
    axis([A 3 min(im) max(im)])
    hold off