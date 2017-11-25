<h2>Zadanie projektowe:</h2>
Celem zadania projektowego jest stworzenie klienta i wieloprocesowego serwera TCP.

<h2>Przygotowanie do ćwiczenia:</h2>
W ramach przygotowania do ćwiczenia należy zapoznać się ze sposobem tworzenia zarówno aplikacji klienckich jak i serwerów, opartych o protokół TCP, w języku C.

<h2>Realizacja ćwiczenia:</h2>
<ol>
  <li> Każdy ze studentów realizuje projekt samodzielnie.</li>
  <li>Program serwera ma realizować następujące funkcje:</li>
    <ol>
      <li>możliwość podania z linii poleceń portu, na, którym ma nasłuchiwać;</li>
      <li>możliwość obsługi wielu klientów jednocześnie poprzez wykorzystanie procesów potomnych;</li>
      <li>dla każdego z klientów serwer tworzy listę wiązaną, w której przechowuje kolejne wartości liczb całkowitych przesłane przez klienta;</li>
      <li>na żądanie klienta serwer wykonuje jedną z operacji:</li>
        <ol>
          <li>sumowanie przesłanych liczb</li>
          <li>odejmowanie przesłanych liczb</li>
          <li>uszeregowanie rosnąco</li>
          <li>uszeregowanie malejąco</li>
        </ol>
        i wysyła odpowiedź do klienta;
      <li>po wysłaniu odpowiedzi serwer czeka na kolejne informacje od klienta;</li>
      <li>po zakończeniu połączenia przez klienta proces obsługujący go powinien zostać zamknięty.</li>
    </ol>
  <li>Program klienta ma pozwalać na realizację następujących funkcji:</li>
      <ol>
        <li>możliwość podania z linii poleceń adresu IP i portu, na którym nasłuchuje serwerem;</li>
        <li>możliwość nawiązania połączenia TCP z serwerem;</li>
        <li>możliwość przesłania liczb wprowadzonych przez użytkownika do serwera;</li>
        <li>możliwość żądania wykonania przez serwer jednej z podanych w punkcie 2.i operacji;</li>
        <li>Wyświetlenie odebranego wyniku;</li>
        <li>możliwość podjęcia decyzji przez użytkownika o zakończeniu lub dalszym działaniu programu.</li>
      </ol>
</ol>
      
<h2>Wymagania:</h2>
Historia prowadzenia i dokumentacja projektu powinna znajdować się na platformie github.com (lub innej obsługującej system kontroli wersji git).
