import { sleep } from 'k6';
import http from 'k6/http';

export const options = {
  vus: 10000,
  duration: '30s',
};

export default function() {
  http.get('http://localhost:8080/health');
  sleep(1);
}
